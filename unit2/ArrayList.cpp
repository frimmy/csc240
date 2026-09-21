// Dequeue add
class DequeueArray : public Array {

  private:
    array<T> a;
    int j;
    int n;

  public:
    void resize() {};
    void add(int i, T x) {
        if (n + 1 > a.length)
            resize();
        if (i < n / 2) { // shift a[0],..,a[i-1] left one pos
            j = (j == 0) ? a.length - 1 : j - 1;
            for (int k = 0; k <= i - 1; k++)
                a[(j + k) % a.length] = a[(j + k + 1) % a.length];
        } else { // shift a[i],..,a[n-1] right one pos
            for (int k = n; k > i; k--)
                a[(j + k) % a.length] = a[(j + k - 1) % a.length];
        }
        a[(j + 1) % a.length] = x;
        n++;
    }

    // guarantees shifts are never more than min(i, n-1) elems
    // run time of ad(i,x) = O(1 + min(i, n-1))
    // remove(i) is similar! --
    // shifting elems a[0],...,a[i-1] right by one
    // or a[i+1],...,a[n-1] left by one
    // remove(i) never spends more than O(1 + min(i, n - i))
    T remove(int i) {
        T x = a[(j + i) % a.length];
        if (i < n / 2) { // shift a[0],..,[i-1] right one
            for (int k = i; k > 0; k--) {
                a[(j + k) % a.length] = a[(j + k - 1) % a.length];
            }
            j = (j + 1) % a.length;
        } else { // shift a[i+1],..,a[n-1] left one pos
            for (int k = i; k < n - 1; k++)
                a[(j + k) % a.length] = a[(j + k + 1) % a.length];
        }
        n--;
        if (3 * n < a.length)
            resize();
        return x;
    }
}

// Summary
// * get(i), set(i,x) in O(1) per op
// * add(i, x), remove(i) in O(1+min(i, n-1)) per op
