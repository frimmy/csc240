---
name: check-submission
description: >-
  Verify a CSC-240 (Oakton C++ Data Structures) lab is ready to hand in on D2L
  before it's zipped and uploaded. Use whenever Adrian says "check Lab N",
  "check my submission", "is this ready to submit", "package Lab N", or is about
  to turn in any lab / AI transcript / mini-oral / group lab for this course.
  Runs the course's naming rules, clean-folder compile, provided-driver check,
  and Feature Documentation check, then reports pass/fail per item. This is a
  verification skill — it reads and builds the work and reports; it never writes
  or fixes the graded code (that's the student's job).
---

# Check CSC-240 lab submission

Verify a finished lab meets the course submission rules **before upload**, and report
each check as pass / fail / flag. Do not write, complete, or fix graded code — if a
check fails, describe it in words and let Adrian fix it. Bugs you happen to notice may
be pointed out in words, not patched.

Last name for all submissions: **Frimpong**. Source of truth for the rules:
`~/Downloads/How to Submit Your Work - CSC-240-0C1 - C++ Data Structures.pdf`.

## How labs are laid out in this repo

Work lives under `unitN/`. A provided starter usually arrives as `LabNN_Files.zip`
(and unzips to a `LabNN_Files/` folder) containing the driver(s), headers, and any
input `.txt` files. The student's finished submission is a **separate** file named
`Lab<N>_Frimpong.cpp` or `Lab<N>_Frimpong.zip` — don't mistake the provided
`LabNN_Files.zip` for the submission.

## Procedure

Run these in order and report a table at the end.

### 1. Locate the work and the provided starter
Find the lab's working files and the provided `LabNN_Files.zip` (or `LabNN_Files/`).
Extract the starter to a scratch dir so you can diff against originals later. If no
assembled `Lab<N>_Frimpong.*` exists yet, say so — that's expected mid-work, but it
means the lab isn't packaged.

### 2. File name
Check the intended submission name against the exact pattern (`<LastName>` = `Frimpong`):

| Submitting | Pattern | Example |
| --- | --- | --- |
| Lab, one file | `Lab<N>_<LastName>.cpp` | `Lab1_Frimpong.cpp` |
| Lab, more than one file | `Lab<N>_<LastName>.zip` | `Lab9_Frimpong.zip` |
| AI Learning Transcript | `Unit<N>_AITranscript_<LastName>.pdf` | `Unit5_AITranscript_Frimpong.pdf` |
| Mini Oral video | `Lab<N>_MiniOral_<LastName>.mp4` | `Lab11_MiniOral_Frimpong.mp4` |
| Group Lab | `GroupLab_Last1_Last2_Last3.zip` | `GroupLab_Smith_Jones_Lee.zip` |

The PDF examples are **not** zero-padded (`Lab1`, `Lab9`). Adrian's past submissions
have used zero-padded names (`Lab05_Frimpong.zip`), so if you see padding, flag it for
him to confirm rather than assuming either way. One file → `.cpp`, not `.zip`; only zip
when the lab genuinely needs more than one file.

For an AI Learning Transcript, the content checks (seed prompt, exchange count, required
elements, reflection) live in the **`check-transcript`** skill. Run that instead of the
lab checks below.

### 3. Zip completeness (multi-file labs)
A submission that won't compile because a header is missing is graded as it arrived.
List what the zip would contain and confirm **everything needed to build and run** is
present: every `.h`, every `.cpp`, the driver, and any input `.txt` the program opens.
Grep the sources for `#include "..."` and file-open calls (`ifstream`, `.open(`, string
literals ending in `.txt`) and confirm each referenced file is included. Also compare
against the provided starter's contents — if the starter shipped a file (e.g. an extra
driver or an input `.txt`) that has no counterpart in the work dir, flag it as possibly
a missing lab part rather than silently dropping it.

### 4. Clean-folder compile
Copy exactly the files that would be submitted into a fresh scratch dir and build there
(`g++ -std=c++17 -Wall`). Building in the work dir hides unsaved edits and headers the
IDE resolves elsewhere; a clean folder catches both. Report success/failure and any
warnings.

### 5. Provided driver vs. modifications
The rule is "run the provided driver unmodified and confirm output matches the lab doc."
Diff each driver against the provided original from the starter zip. Two cases:
- **Whitespace / formatting / include-order only** → effectively unmodified, pass.
- **Substantive changes** (added tests, new function calls, changed logic) → flag it.
  Many labs ask the student to *implement* functions and add tests that exercise them,
  in which case driver edits are expected — but the check can't know that from the PDF
  alone, so surface the diff and tell Adrian to confirm against the lab document.
Then run the program and show the output so he can compare it to what the lab doc shows.

### 6. Feature Documentation block (only labs with a creative feature)
This applies **only when the lab has a creative feature component** (the Creative Final
Feature points) — not every lab does. If the lab has no creative feature, skip this check
and note it as N/A rather than a fail. Ask Adrian if it's unclear whether this lab has one.

When it does apply: at the top of the main file, a comment block answering all four
questions (worth 2 of the 10 Creative Final Feature points — the most-forgotten item):

```cpp
// What does your feature do?
// What concept from your AI Learning Query did it use?
// What did you try that did not work?
// What would you do next if you had another week?
```

Confirm the block exists **and all four lines are actually answered** — not blank, not
"n/a" on every line.

### 7. Lab-specific written deliverables
Separate from the creative feature, some labs require a written answer submitted **as a
comment in the code**, graded under Design and Documentation — e.g. "state the invariant
above `ReplaceItem`," "explain your Big-O above the function." These are easy to miss
because they look like ordinary code. If Adrian has pasted the lab's "be ready to answer"
/ oral-prep questions, check which are marked *submitted in writing with your code* and
confirm each has a real answer in the right place (above the named function, etc.). Don't
write these answers — they're graded documentation of Adrian's own code; only verify they
exist and are substantive, and name precisely what's missing.

### 8. Upload reminder
Remind Adrian: D2L shows a submission receipt; no receipt means it didn't upload. He can
resubmit freely before the deadline (last submission is graded, no penalty). Late work is
not accepted — the dropbox closes automatically.

## Report format

End with a compact table: check name → ✅ pass / ❌ fail / ⚠️ flag, one line each, then a
short "before you upload" list of the concrete things left to do. Lead with whether the
lab is submit-ready overall.
