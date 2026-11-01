# Lab 10 — Recursion: Count Paths and Newton's Method — TODO

**50 pts · Due Sun Oct 25, 11:59 PM (tonight) · Creative Final Feature (20 pts) · Mini Oral 4 · Unit 5 AI Learning Transcript**
Source: `unit5/Lab10_Files/Lab 10_ Recursion - Count Paths and Newton's Method (50 pts) ….pdf`
(no HTML spec for this lab; the PDF's text was checked against the rendered pages and matches.)

Updated 2026-10-25 from: the lab doc, a clean-folder build (`g++ -std=c++17 -Wall -Wextra -g`),
a run of `CSC240_RecursionDriver.cpp`, `leaks --atExit`, and a scratch probe that counted calls.
I counted the calls in a throwaway copy in the scratchpad, not in your files.

**Status after "pass 1":** it builds with 0 warnings, the driver prints 20 / 70 / 2 / 3 / 3 / 4,
and `leaks` reports **0 leaks**. The output looks right, but the memoization doesn't work
yet (A1), the original NumPaths is gone so nothing can be compared (A2), Part B returns
`int` and has no iterative version (B1–B2), and the CFF, Feature Documentation, and Q1
invariant comment haven't been started.

Starter files (from commit `ecb2dd8`): all three `.cpp` files. You've only changed
`CSC240_RecursionDriver.cpp`. `RecursionInefficiency.cpp` and `RecursionLecture.cpp` are
unchanged lecture samples, and the lab says the driver is "of your own design."

| Rubric | Pts | Where it's covered |
| --- | --- | --- |
| Correctness & Specification (driver demonstrates every requirement) | 15 | A1–A3, B1–B3 |
| Data Structure Implementation (memo table is yours, memory correct) | 8 | A1, A4 |
| Design & Documentation (interface/impl separated; pre/post on every function) | 4 | D1–D2 |
| Coding Conventions | 3 | D3 |
| CFF: runs (6), creative (4), uses AI-query concept (6), Feature Doc (4) | 20 | C |

Suggested order for tonight: **AI Learning Query → A1 → A2 → B1 → B2 → A3 → C → D → Submit.**
The query has to come *before* the CFF, and its topic is the bug in A1, so it should help with A1 too.

---

## 0. AI Learning Query (Unit 5 graded transcript)
The lab says: "This is the graded transcript for Unit 5 — submit it to the AI Learning
Transcript 5 dropbox." Use the prompt exactly as written. Have at least 5 exchanges,
paste your own code at least once, and push back at least once.
- 📄 `unit5/` already has `AI_Transcript_Lab7_Frimpong.pdf`. The Lab 10 doc says *this*
  lab is Unit 5's transcript, so check the D2L Overview table to confirm which one counts.
- **Done when:** the transcript is saved and **check-transcript** passes.
- **Good code to paste:** your current `RecurseNumPaths`. Ask about the "when I check
  the table vs. when I write to it" part using your own code.

---

## A. Part A — Count Paths

### ✅ A1. The memo table never gets a hit — FIXED 2026-10-25
Re-probed after your fix. It now builds **one table per top-level call**, memo results
MATCH the original for n = 1, 2, 4, 5, 10, 14, 17, and `leaks` still reports 0. Call counts at
n=14 went from 20,801,199 to 339, and at n=17 from 1,202,160,779 to 513 (the plain version took about 3.4 s at n=17; memo took about 5 µs).
The n=5 count isn't listed here on purpose. Predict it (question 2 below), then measure it with
your own instrumentation for Be-Ready Q2. The questions below are still worth answering for the oral.

Original finding, kept for reference:
**Evidence** (scratch probe, same results with your memo version and with the starter's plain recursion):

| n | result | your calls | original (no memo) calls |
| --- | --- | --- | --- |
| 4 | 20 | 39 | 39 |
| 5 | 70 | 139 | 139 |
| 10 | 48,620 | 97,239 | 97,239 |
| 14 | 10,400,600 | 20,801,199 | 20,801,199 |

The memo version makes **exactly as many calls** as the unmemoized one. Each of those calls
also goes through the wrapper, which allocates and frees a whole fresh N×N table.
At n=14 that's about 20.8 million tables. `leaks` reports 0 because every table is freed,
but none of them is ever read back. The recursive case calls back into the function that
*creates* the table, not the one that *uses* it. So every sub-call starts with a
brand-new, all-zero table, and the "already computed?" check can never be true.
- **Done when:** the memo version's call count for `(1,1,5)` is far below 139 (work out
  the exact number before you measure it), and its result still equals the original for
  every n you test.
- **Check for understanding**
  1. *Draw it first:* draw the call tree for `(1,1,3)` with your current code. Next to each
     call, write the address of the table it can see. How many different tables are there,
     and how many cells does any one of them ever have filled?
  2. *Predict, then run:* once the memo works, how many distinct `(row, col)` pairs can
     reach the recursive case for n=5? How does that relate to the call count you expect?
  3. *Explain it back:* your "uncomputed" marker is 0. Can a non-base cell ever
     legitimately hold 0 paths in *this* problem? What about in a version of the problem
     with blocked cells? (This is the third question in the AI query.)

### A2. Keep the original NumPaths and show identical results (Correctness)
The spec requires you to "confirm your memoized version produces identical results to the
original," and to compare "both working versions."
**Progress (2026-10-25):** `OrigNumPaths` is back, and the driver prints it next to the memo version
for n=4 only, as two numbers under the label "orig numpaths". Still to do: run several n
(including 1 and 2) and print an explicit match/mismatch line.
- **Done when:** both versions exist side by side under distinct names. The driver runs both
  for several n (include n=1 and n=2), and it prints a match/mismatch line, not just
  two numbers for a reader to compare by eye.
- **Check for understanding**
  1. *Challenge and verify:* what does each version return for n=1? Does a 1×1 grid
     having "1 path" make sense? Does your memo table code still behave when n=1?
  2. *Predict, then run:* the starter driver called `NumPaths(0, 0, 4)`, and the spec
     calls `(1, 1, 4)`. Predict both results before running them. Which one is the 4×4 grid?

### A3. Hand trace of the 20 paths + time/space comparison (Correctness; Be-Ready Q2, Q3)
Spec item 1 asks you to trace the 20 paths by hand, and item 3 asks you to compare time *and*
space. Neither is in the repo yet. The driver also only prints "20". It doesn't show
the trace agreeing (Q3: "show your program's output agreeing").
- **Done when:** you have (a) the hand trace written down, as paper or a comment block, ready for
  the oral, (b) actual call counts for `(1,1,5)` with and without memo (Q2), and (c) a short
  written comparison covering Big-O time, extra space (table + stack depth), and a measured
  timing at an n where the difference is visible.
- **Check for understanding**
  1. *Ask about cost:* Big-O time of each version in terms of n. Then the extra space:
     the table is N×N, but what's the maximum recursion *depth* in each version? Do they differ?
  2. *Predict, then run:* time both versions at n=14 and n=17. Predict the ratio first.
     Your probe at n=14 already showed about 20.8M calls without memo.
  3. *Challenge and verify:* what's the smallest n where the answer no longer fits in an
     `int`? Do the arithmetic (it's a binomial coefficient) before you try it. What would
     the driver print?

### A4. Table memory (Data Structure Implementation)
Allocation and freeing already balance (0 leaks). Keep it that way after A1. The fix should
lead to **one** table per top-level call.
- **Done when:** `leaks --atExit` still reports 0, and you can say how many times
  `new int[...]` runs for a single `NumPaths(1,1,5)`.
- **Check for understanding**
  1. *Explain it back:* the lab says "N×N array," but you only ever index rows/cols 1..n−1
     (the base case catches n). Which cells of your table are never touched? Is that worth
     changing or just worth a comment?

---

## B. Part B — Newton's Method

### B1. It returns an integer, so it can't find an irrational root (Correctness)
**Evidence** (scratch probe):

| x | yours | `std::sqrt` |
| --- | --- | --- |
| 2 | 1 | 1.41421 |
| 10 | 3 | 3.16228 |
| 21 | 4 | 4.58258 |

`-Wconversion` flags line 57: "implicit conversion turns floating-point number into integer".
The spec says "a nonnegative **real** number x," but `x` is an `int`, both functions return
`int`, and the tolerance of 0.75 is very loose. The driver's own label, "Newton SQRT: 21 = 4,"
expects the truncated answer.
- **Done when:** non-perfect squares print a decimal result (2, 10, 21, and a non-integer
  input like 0.25), it's within ε of the true root (|a² − x| ≤ ε), and ε is a named value
  you can state in the oral (Q4).
- **Check for understanding**
  1. *Predict, then run:* with a=x as the start, what is a after one step for x=0.25? Is
     the first guess above or below the root, and does that change for x<1?
  2. *Explain it back:* the spec's stopping test is about a² − x, not about a − √x. Why
     test that quantity, when you're converging on a number you can't write exactly?
  3. *Challenge and verify:* trace x=0 by hand. Step 3 divides by 2a. Does your code ever
     reach that division when x=0? Prove it either way.

**Re-checked again 2026-10-25: mostly fixed.** Both versions now return `float` and take a shared
`tolerance` parameter (default .75). They agree with each other, and every result meets |a² − x| ≤ ε at
ε = 0.75, 1e-3, and 1e-5. `-Wconversion` no longer flags the returns. Still open:
- **`x` is still `int`.** Passing 0.25 gets silently truncated to 0 before the function runs, so
  `NewtonsSqrt(0.25)` returns 0. The spec says "nonnegative **real** number x."
- **Default ε = 0.75 is loose.** √2 comes out as 1.5, which meets the test but is 0.086 off.
  Pick the ε you'll defend in the oral (Q4).
- **Driver:** the labels still say "21 = 4", the "9 = 3" block is duplicated, and the driver never passes an ε or a non-integer x.

Earlier finding: Both versions still return `int` with ε = 0.75. At x = 2, 10, 21, 50
they return 1, 3, 4, 7 (std: 1.41, 3.16, 4.58, 7.07). `-Wconversion` now flags two
float→int returns, at lines 66 and 83.

### B2. Iterative version is missing (Correctness)
**Progress (2026-10-25):** `IterativeNewtonsSqrt` exists, and it agrees with the recursive one for
x = 0, 1, 2, 4, 10, 21, 50, 1e6. Still to do: the driver tests the iterative version only on x=21, and each
function declares its own `tolerance` (two copies that can drift apart, see B1's "named ε").
Also, the `// base case` comment above the `while` is copied from the recursive version and doesn't describe a loop.
The spec says to "implement and test **both** an iterative and a recursive version." Only the recursive one exists.
- **Done when:** the iterative and recursive versions return the same value for the same x and ε,
  and the driver shows both side by side for several x (including 0 and 1).
- **Check for understanding**
  1. *Explain it back:* the recursive version's base case corresponds to which part of the
     loop? And the recursive call corresponds to which part?
  2. *Ask about cost:* both take the same number of steps. What's the extra *space* of each?
     (This is Be-Ready Q5. To see whether the compiler turned the recursion into a loop, compare
     max depth or stack use at `-O0` vs `-O2`.)

### B3. Tolerance experiment (Be-Ready Q4)
- **Done when:** you've run with your chosen ε and with ε = 1e-18, and written down what you observed.
- **Check for understanding**
  1. *Predict, then run:* about how many significant digits can a `float` hold, and a
     `double`? Can a² − x ever get within 1e-18 for x=2? What does the recursion do if the
     base case is never satisfied?
  2. *Challenge and verify:* does the answer to (1) change if you switch the type? Try both.

---

## C. Creative Final Feature (20 pts)
This hasn't been started. Pick **one part** to extend *after* the AI query. The rubric gives 6 of the 20
points for "demonstrates the concept from your AI Learning Query." That query was about
memoization (what's stored, check vs. write, uncomputed vs. zero, space trade-off), so a
Part A feature has the most direct link. The lab's ideas are: return the paths themselves, a
bottom-up iterative DP table, or call-count instrumentation with and without memo. A Part B feature
is fine too if you can tie it back to the query.
- 📄 Instrumented call counts are also Be-Ready Q2. If you choose that, confirm it still
  counts as "creative and self-chosen" (4 pts), or go a step further than the oral requires.
- **Done when:** the feature runs from the driver without errors, and it's clearly something the
  spec didn't ask for.
- **Feature Documentation** (4 pts): answer all four questions in a comment block **at the top of
  your main file**: what it does, the AI-query concept it used, what didn't work, and what you'd do next week.
- **Check for understanding**
  1. *Ask about cost* (bottom-up DP): which order must you fill cells in so every cell's two
     neighbors are ready? What's the space if you only keep one row at a time?
  2. *Explain it back* (returning paths): how many paths exist for n=10 (see A1)? What
     does that mean for printing or storing them all? Can memoization help when the
     *output itself* is exponential?

---

## D. Design, Documentation, Conventions (7 pts)

### D1. Interface separated from implementation (Design & Doc, 4 pts)
Everything is in one `.cpp`. The rubric line is "Interface separated from implementation."
- **Done when:** your NumPaths and Newton functions are declared in a header and defined
  separately, and the driver only includes the header. Then confirm the clean-folder build still works.
- **Check for understanding**
  1. *Explain it back:* `RecurseNumPaths` is a helper that callers shouldn't call directly.
     Does it belong in the header? What would it mean to leave it out?

### D2. Pre/postconditions + Q1 invariant comment
No function you wrote has a pre or post comment. Be-Ready Q1 is **submitted in writing**:
state the memo table's invariant (what's true of a cell once it's been written) as a comment.
- **Done when:** every public function you wrote or changed has pre/post comments that are true
  for *your* code (e.g. what's the precondition on x and ε?), and the Q1 invariant sits
  above the memo function.
- **Check for understanding**
  1. *Explain it back:* write the invariant *before* you fix A1. Is it currently true?
     (If it's true but the code is still slow, the invariant isn't the problem. What is?)

### D3. Coding Conventions (3 pts)
- [ ] The file header still reads `Name: CSC240_RecursionInefficiency.cpp / Author: Ivan
      Temesvari / 2/22/2023`. Make it your name, the correct file name, and a correct date and description.
- [ ] Dead code: `powerOf2` is never called, and `<chrono>` and `<time.h>` are unused unless your
      timing in A3 uses them.
- [ ] Driver labels: the duplicated "Newton SQRT: 9 = 3" block, plus labels that match the new real-valued output.
- [ ] 📄 The Oakton C++ Coding Conventions doc isn't in the repo. Skim it on D2L for naming
      (e.g. is it `NewtonsSqrtRecurse` vs. a `camelCase` rule?) and the header-comment format.

---

## Cross-cutting

| Version | Time | Extra space | Max depth |
| --- | --- | --- | --- |
| NumPaths, plain recursion | *you fill in* | | |
| NumPaths, memoized | | | |
| (CFF) bottom-up DP, if chosen | | | |
| Newton, recursive | | | |
| Newton, iterative | | | |

- `const`: which parameters never change inside each function? Would marking them `const`
  have caught anything here?
- Concept: Part A is *tree* recursion and Part B is *linear*. Using your own call counts, explain
  why memoization changes A dramatically but would do nothing for B.
- Concept: the STL note mentions `std::unordered_map` as a memo table. For *this* problem, is
  the key space dense or sparse? So which data structure wins, and why?

---

## Be Ready to Answer (Mini Oral 4)
Record yourself answering these with your code on screen. Only Q1 is submitted in writing (D2).
- Q1 memo invariant (D2) · Q2 call counts for n=5 with/without memo (A1, A3) · Q3 hand trace plus
  matching output (A3) · Q4 ε and 1e-18 (B3) · Q5 iterative vs. recursive stack use (B2.2)

---

## Submit
- [ ] Clean-folder build `g++ -std=c++17 -Wall -Wextra`, no warnings (also try `-Wconversion` once and look at what it flags)
- [ ] `leaks --atExit -- ./prog` reports 0 leaks
- [ ] The driver demonstrates: 4×4 = 20 for both versions, a memo-vs-original match for several n, call counts or timing,
      both Newton versions on non-perfect squares, and the CFF
- [ ] Feature Documentation block (4 questions) at the top of the main file
- [ ] Q1 invariant comment
- [ ] Leave the stray build output out of the zip: `Lab10_Files/main` and `main.dSYM/` (untracked) are there now
- [ ] Package with the correct name (likely `Lab10_Frimpong.zip`) and run **check-submission**
- [ ] AI Learning Query transcript → run **check-transcript** → AI Learning Transcript 5 dropbox
- [ ] Mini Oral 4 recording (check its own due date on D2L)
- [ ] Confirm the D2L receipt before **11:59 PM tonight**. Late submissions aren't accepted.
