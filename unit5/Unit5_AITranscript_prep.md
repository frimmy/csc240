# Unit 5 AI Learning Transcript: prep sheet (Lab 10 query)

Prep only, don't submit this. The questions in the transcript have to be **yours, in your own words**,
and the pushback and summary have to come from what actually happens in the conversation.
This sheet says *what to find out* and *what to bring* for each exchange, mapped to the rubric
(`AI_Transcript_Rubric.pdf` p. 9).

File to submit: **`Unit5_AITranscript_Frimpong.pdf`** → the AI Learning Transcript 5 dropbox
(not the Lab 10 folder). Lab 10 is due tonight. Do this before you write the Creative Final Feature,
since the lab says the CFF should grow out of it.

## Setup
- If you want the AI to act as a tutor, turn on learning mode or put the tutor instructions in the
  tool's custom instructions. Don't prepend them to the seed. The seed has to be your first
  message, **unchanged**.
- Seed prompt (from the Lab 10 doc, paste exactly):

> I have a recursive NumPaths function in C++ that recomputes the same subproblems many times, and I want to add memoization. Do not write the memoized version for me. Help me understand what exactly gets stored, when I check the table versus when I write to it, and how to tell an uncomputed cell from a legitimately computed zero. Then tell me what memoization costs me in space and whether that trade is always worth making.

- Paste **every AI reply in full**. Copy as text or use the tool's export, not screenshots.

## Material you already have (all yours, from this lab)
| Thing | Where | Good for |
| --- | --- | --- |
| Your first memo attempt: right answers, but no speedup | `git show 3ab49b9:unit5/Lab10_Files/CSC240_RecursionDriver.cpp` (`RecurseNumPaths`) | Own-code exchange, difficult-thing exchange |
| Your fixed memo version | the current `RecurseNumPaths` | Draw it first, invariant (Be-Ready Q1) |
| Call counts you measure **yourself** with/without memo | your own instrumentation (Be-Ready Q2) | Predict-then-run, pushback evidence |
| Your Newton output at ε = 0.75 and a tighter ε | driver run | Optional: tie-in to Part B / CFF |

Measure the call counts with your own instrumentation before the conversation, so the numbers you
paste are from your machine.

## Exchange plan (at least 5 after the seed; aim for 6–7 so a weak one doesn't sink you)

**Ex 1: Explain it back (Move 3).** After the first answer, restate in your own words what one table
cell *means* (which subproblem, what number). Ask the AI to correct your restatement, not to re-explain.
- What to find out: whether your mental model of a cell and its index matches your actual table.

**Ex 2: Your own code, "don't fix it" (Move 5 + Draw it first). Covers "paste your own code."**
Paste your *first* attempt (commit `3ab49b9`). Say what you observed: correct results, but
the call count wasn't any better. Ask it to point you at *why* without rewriting it.
- What to find out: how many tables existed during one top-level call, and why the check never hit.
- Have your own drawing of the call tree for a small n ready, and say what you drew.

**Ex 3: Something difficult + your 2–3 sentence summary.** Pick the part that actually tripped
you up. Likely candidates are "check vs. write timing" or "why a fresh table per call defeats the
memo". Work through it until it clicks, then write **MY SUMMARY** in 2–3 sentences of
your own words. Don't paraphrase the AI's phrasing.

**Ex 4: Predict, then run (Move 2).** Before measuring, state your prediction for the memo call
count at n=5 and *why*. Then paste your measured counts for both versions and ask whether the gap
matches the tree shape. (This is also your Be-Ready Q2 rehearsal.)

**Ex 5: Uncomputed vs. legit zero (Move 4 challenge).** The seed asks about it, so challenge whatever
the AI says against *your* problem. Can any non-base cell in your grid legitimately be 0? What changes
if cells could be blocked? Ask it to defend its sentinel advice for both cases.

**Ex 6: Ask about cost.** The space trade: your N×N table vs. recursion depth, and whether the trade is
"always worth it". Bring your own observation that for tiny n, memo can be *slower* than the plain version.
Time it yourself at n=1–3 vs. n=14.

**Ex 7 (optional): Connect to your CFF.** Say which CFF direction you're considering and ask what
concept from this conversation it should demonstrate. Ask for questions to consider, not an implementation.

## Pushback: you can't plan it, but watch for these
Pushback counts only if you say **why** the AI is wrong, ideally with pasted compiler or program output.
"Are you sure?" alone doesn't count. These are the usual places an AI slips on this topic:
- It suggests `std::unordered_map` or `std::map`/`vector` as the memo table. The rubric says to call
  that out: the lab asks for an N×N array you manage yourself. (The STL note in the lab mentions
  `unordered_map` only as ungraded reading.)
- It writes the memoized function despite the seed saying not to. Call out the broken instruction,
  and don't use that code (the rubric gives it no credit).
- It claims a call count, depth, or table size that disagrees with what *your* instrumentation printed.
  Paste your output.
- It says memoization is always worth it, or never costs anything, when your timing at small n says otherwise.
- It uses table indices or grid bounds that don't match your `(1,1)`→`n` convention.

## Closing reflection (last message, all three parts)
1. What you learned (one or two concrete things, not "memoization is useful").
2. Where the tool **helped** and where it **misled** you (name the exchange).
3. **One question you still have.**

## After exporting
Run **check-transcript** on `Unit5_AITranscript_Frimpong.pdf` before uploading.
