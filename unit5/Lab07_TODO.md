# Lab 7 — Recursive StackSum and PowerStack — TODO

**20 pts · Due Sun Oct 18, 11:59 PM** · No Creative Final Feature · No Mini Oral
Source: `unit5/Lab 7_ Recursive StackSum and PowerStack (20 pts) ….pdf`

Updated 2026-10-18 from the lab doc + clean-folder build/run + `leaks --atExit` of both drivers.

**Status:** `StackSum` and `PowerStack` don't exist yet in either class. The files in
`Lab07_Files/` look like the untouched provided zip. Both build and run.

Each task has a **Done when** and **Check for understanding** questions. Answer them on
paper *before* you write the code, then again after. If your answer changed, that's the
learning, and it's exactly what Major Oral Inquiry will ask.

| Rubric | Pts | Where it's covered |
| --- | --- | --- |
| Correctness & Specification (driver demonstrates every requirement, edge cases) | 10 | A, B, C |
| Data Structure Implementation (no STL substitute, memory correct) | 5 | A, B, D |
| Design & Documentation (pre/post on every function you write; Q1 invariant comment) | 3 | A3, B3 |
| Coding Conventions (Oakton conventions) | 2 | E |

Suggested order for tonight: **A1 → A2 → C1 (array Print) → B → C2/C3 → A3/B3 → D → E → Submit.**

---

## Before you start: AI Learning Query (not submitted, but recommended)
Start a conversation with the lab's query exactly as written (it's about `StackSum`'s
base case and the "way back up"). The lab asks for at least 5 exchanges, at least one paste of
your own code, and at least one pushback. This lab isn't a submitted transcript, so you
don't need to run **check-transcript**, but it's good practice.

---

## A. `StackSum()` — both classes

Spec: `int StackSum()`. It returns the sum of the items. **Postcondition: the stack is unchanged.**
The lab's hint: "you cannot look at the buried items without removing them, so the work
happens on the way back up the recursion."

### A1. Implement recursively in `StackTypeLinked`
- **Done when:** sum is correct *and* `Print()` before and after the call show the same stack.
- **Check for understanding**
  1. *Explain it back:* the signature takes **no parameters**. So what makes each
     recursive call work on a *smaller* problem than the one before it?
  2. *Draw it first:* for a 3-item stack, draw the stack and the call stack at the deepest
     call. Which items are physically in your stack right then, and where are the others
     being held? (This is Be-Ready Q2.)
  3. *Predict, then run:* if you only handled the way down and returned without
     restoring anything, what would `Print()` show after the call?

### A2. Implement recursively in `StackType` (array)
- **Done when:** same check as A1, on the array stack.
- **Check for understanding**
  1. The array class has `operator[]`, so you *could* just walk indices. Would that
     still satisfy "recursive" and the spirit of §4.2.4 ("work happens on the way back up")?
     Decide, and be ready to defend it. Whichever you choose, the reason belongs in your comment.
  2. *Ask about cost:* Big-O time, and the maximum recursion depth, for n items. Is it the
     same for both classes? (Be-Ready Q4.)
  3. *Challenge and verify:* what's the precondition, and what does your function do on
     an empty stack? Is that a crash, an exception, or 0? Is it allowed to be any of those?

### A3. Q1 invariant comment (graded, Design & Documentation)
Be-Ready Q1 is **submitted in writing**: state the invariant your `StackSum` recursion
maintains about the stack at each level, as a comment **above the function**. Put it in
both classes, plus a Function/Pre/Post block matching the lab's wording.
- **Done when:** a reader could check the invariant against your code line by line.
- **Check for understanding**
  1. At the moment a call *returns*, what's true about the stack compared to when that
     call *started*? That sentence is most of your invariant.

---

## B. `PowerStack()` — both classes

Spec: each item becomes `item ^ (item below it)`, and the bottom item uses the **top** as its
exponent (it wraps around). Precondition: at least 2 items.

### B1. Implement in `StackTypeLinked`
- **Done when:** the worked example (top→bottom `2 5 3 4 6`) becomes `32 125 81 4096 36`.
- **Check for understanding**
  1. *Draw it first:* the bottom item needs the **original** top value. By the time you
     reach the bottom, has the top already been overwritten? What do you need to have
     saved, and when?
  2. Each item is raised to the item *below* it. When you process an item, has the one
     below it changed yet? Does your order of updates depend on that?
  3. *Ask about cost:* `pow` from `<cmath>` returns a `double`. What could go wrong storing
     that into an `int`? Is writing your own integer power loop cleaner? (Not an STL
     container, so either is allowed. Choose deliberately.)

### B2. Implement in `StackType` (array)
- **Done when:** same worked example output on the array stack.
- **Check for understanding**
  1. Which index holds the top, and which holds the bottom? Map the worked example onto
     `items[0..top]` before writing anything.
  2. Does the array version even need recursion here? The spec doesn't say "recursive" for
     `PowerStack` (only for `StackSum`). Be ready to say which you chose and why.

### B3. Pre/post comments on `PowerStack` in both classes (Design & Documentation)

---

## C. Driver demonstrates every requirement (Correctness, 10 pts)

The rubric says requirements must be "**demonstrated by the driver**", so you're expected
to edit both drivers (they don't call either function yet).

### C1. Array `Print()` prints indices, not values ⚠️ do this before B2
Current output under "Top:" is `0 1 2 3 4 5`. The iterator's `operator*` returns an
**index** (see the iterator header comment), and `Print()` sends it straight to `cout`. The
driver's range-for gets it right with `stack[i]`. It also prints **bottom-first** under
a "Top:" label. If you leave it, your PowerStack output can't match the worked example.
- **Done when:** array `Print()` shows the values, top first, matching the linked `Print()`.
- **Check for understanding**
  1. In `for (auto i : stack)`, what type is `i`, and which member calls does that loop
     turn into?
  2. Why is "top first" free for the linked stack but not for a forward index walk?
  3. `begin()` prints "The stack iterator initializes." every time. Does that line
     help or hurt your demonstration output?

### C2. Add tests to both drivers
At minimum, on an **int** stack in each driver:
- [ ] StackSum on the worked-example stack, with Print before/after (proves "unchanged")
- [ ] PowerStack on the worked example (Be-Ready Q3), with Print before/after
- [ ] the edge case the spec names: PowerStack with exactly 2 items (wraparound with the minimum)
- [ ] (Q5, not graded but asked orally) one-item PowerStack. Do this in a scratch file if it crashes.
- **Check for understanding**
  1. The linked driver uses `StackTypeLinked<char>`, and the array driver also has `double` and
     `string` stacks. Will `StackSum` compile if those stacks exist but you never call
     `StackSum` on them? Why? (Hint: when does the compiler generate a template's member function?)
  2. *Predict, then run:* write down your expected output for every new test *before* you run it.

### C3. Clearly labeled output
Label each section of output (e.g. "StackSum (expected: …):", "PowerStack:") so the grader can
match it to the spec without reading the code.

---

## D. Memory (Data Structure Implementation, 5 pts)

`leaks` on the provided linked driver reports **6 leaks / 160 bytes** before you've touched
anything. These are in the provided copy constructor and `operator=`:

| Source | Bytes | Cause (in words) |
| --- | --- | --- |
| `operator=` | 128 (4 nodes from `Push`) | the left-hand stack's old nodes are never freed before rebuilding |
| copy constructor | 16 | temporary `items` array allocated with `new[]`, never released |
| `operator=` | 16 | same temporary-array leak |

The array driver: 0 leaks.

- **Decide:** the rubric says "memory is allocated and released correctly", and these files
  are part of what you submit. Fixing them is optional extra-safe work. If time is
  tight, finish A–C first. Either way, make sure **your new functions add 0 leaks**.
- **Done when:** `leaks --atExit -- ./dr` shows no ROOT LEAK under `StackSum`/`PowerStack`
  (and ideally 0 overall).
- **Check for understanding**
  1. *Draw it first:* draw `anotherStack` right before `operator=` sets `topPtr = nullptr`.
     Which nodes become unreachable?
  2. If your `StackSum` pops and pushes, does each push allocate a *new* node? Does each
     pop free one? Over a whole call, does the count balance?

---

## E. Coding Conventions (2 pts)
- [ ] Match the existing file's style: indentation and brace placement (the linked
      header mixes tabs and spaces).
- [ ] The Oakton C++ Coding Conventions doc isn't in the repo. Skim it on D2L for naming
      and header-comment rules (author/date block?).
- [ ] Fix the copy-pasted `Top()` postcondition in `StackType.h` ("top element has been removed")
      if you're touching comments anyway.

---

## Be Ready to Answer (Major Oral Inquiry)
Only Q1 is submitted (A3). Prepare the rest from **your** code:
- Q2 trace a 3-item StackSum (A1.2)
- Q3 worked-example output and any differences (C2)
- Q4 recursion depth vs. n, when it would overflow, what you'd do in production (A2.2; the
  STL note in the lab says why the standard library avoids recursion)
- Q5 one-item PowerStack (C2)

---

## Submit
- [ ] Clean-folder build of both programs, `g++ -std=c++17 -Wall`, no warnings
- [ ] Both drivers run, and output matches the worked example
- [ ] `leaks --atExit` shows nothing new from your functions
- [ ] Q1 invariant comment above `StackSum` in both classes
- [ ] Package as **`Lab7_Frimpong.zip`** containing both folders. Run **check-submission**, which
      will ask about zero-padding (`Lab07` vs `Lab7`); the course PDF examples aren't padded.
- [ ] Confirm the D2L receipt before 11:59 PM
