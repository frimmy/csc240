---
name: lab-todo
description: >-
  Build a learning-focused TODO list for a CSC-240 lab from the lab document/rubric
  and the provided lab files. Use when Adrian says "make a todo for Lab N", "what's
  left on Lab N", "plan Lab N", "gap check Lab N", or "what do I need to do to make
  Lab N submittable". Builds and runs the drivers, checks for leaks, maps every
  requirement to its current state, and writes a TODO with a "done when" check and
  check-for-understanding questions per task. Describes work in words only; it never
  writes or fixes the graded code.
---

# Lab TODO with checks for understanding

Turn a lab's requirements plus its current files into a TODO list Adrian works through
himself. Every task says **what's wrong or missing (in words)**, **how he'll know it's
done**, and **questions that make him reason about it**. Follow the course rule in
`csc240/CLAUDE.md`: no code in the TODO. That means no fixed lines, no "change X to Y"
snippets, and no pseudo-code close enough to paste.

## Inputs

1. **Lab document / rubric.** It's the source of truth for what's required and how many
   points each part is worth. **Prefer the HTML spec** downloaded from D2L as a zip
   (`unitN/labNN_spec.html.zip`, which unzips to `labNN_spec.html`). If only the zip is
   present, unzip it into the scratchpad. Extract it with
   `textutil -convert txt -stdout labNN_spec.html`. `<pre>` blocks (signatures, worked
   examples) and the grading `<table>` come through intact.
   - **Fall back to the PDF** (`unitN/` or `~/Downloads`) only if there's no HTML. A printed
     PDF can split a code block across a page break, and `pdftotext` can duplicate or
     drop the rows on either side of the break. For any worked example or expected output
     taken from a PDF, look at the rendered page (Read with `pages`) and check row by row.
     Don't trust the extracted text alone.
   - If neither exists, ask for it. If Adrian wants to proceed anyway, mark every
     requirement-dependent item 📄 ("confirm against lab doc") and say so at the top of
     the TODO.
2. **Provided lab files.** This is usually `LabNN_Files.zip` or `LabNN_Files/` (drivers,
   headers, input `.txt`). If there's no pristine starter zip, ask which files are
   instructor-provided versus his. Driver-modification rules depend on it.
3. **Unit number,** which also tells you whether this is the unit's AI Learning
   Transcript lab (see the Overview table on D2L; ask if unknown).

## Procedure

### 1. Extract requirements
From the lab doc (HTML preferred, see Inputs), list each required function/feature, its point value, the rubric
categories (correctness, Design & Documentation, Creative Final Feature, written
answers "submitted with your code"), and any "be ready to answer" oral-prep questions.

### 2. Inventory and build in a clean folder
Copy each program's files to the scratchpad and build with
`g++ -std=c++17 -Wall -Wextra -g`. Record warnings and errors. Never build or write
inside the work folder.

### 3. Run and compare
Run every driver. Compare the output to the lab doc's expected output, and to what the
code's own labels and comments claim. A `Print()` that says "Top:" but prints bottom-up
is a gap even if no doc shows the expected output.

### 4. Memory check
Run `leaks --atExit -- ./prog` (macOS) for each driver. For every ROOT LEAK, name the
function that allocated it and the cause, in words. Leaks in copy constructors,
`operator=`, and destructors are the usual suspects in this course.

### 5. Read for gaps the run can't show
- Rule of Three: a class that owns heap memory without a copy constructor, `operator=`,
  and destructor.
- Untested paths: exceptions never triggered, empty and one-element cases,
  self-assignment, copy independence (deep vs. shallow).
- Wrong or copy-pasted pre/post comments (Design & Documentation points).
- Duplicated logic, dead lines, missing `const`.
- Anything the lab forbids, such as an STL container substituted for the structure
  being built.

### 6. Write the TODO
Write `unitN/LabNN_TODO.md` (zero-pad to match the `LabNN_Files` folder), uncommitted.
Group the tasks by program/class and order them by rubric weight, with correctness
first. For each task include:

- **Title + evidence:** what the build, run, or `leaks` showed (quote the output or byte
  counts), so the gap is observable, not asserted.
- **Done when:** an observable check, such as "`leaks` reports 0", "Print shows values
  top-first", or "output matches page N of the lab doc".
- **Check for understanding:** 2–3 questions using the moves from
  `AI_Transcript_Rubric.pdf`:
  - *Predict, then run*: "predict the output if X; then try it in a scratch file"
  - *Draw it first*: "draw the pointers right before line L; which node is unreachable?"
  - *Explain it back*: "which member calls does this range-for turn into?"
  - *Ask about cost*: "Big-O time and extra space of this approach vs. your sketch"
  - *Challenge and verify*: "what's the smallest input that fires this exception?"

  Questions point at the concept behind the bug without giving the answer. Avoid
  questions whose answer is the fix itself ("should you call delete here?").

End the file with a **Cross-cutting** section (Big-O table, `const`, concept questions)
and a **Submit** section with these steps:
- clean build plus 0 leaks
- Feature Documentation block, if the lab has a Creative Final Feature
- package with the correct name, then run **check-submission**
- if this is the unit's transcript lab, the AI Learning Query plus **check-transcript**

### 7. Report
Summarize in chat: the top gaps by rubric impact, anything blocked on the lab doc (📄),
and the TODO path. Don't restate the whole file.
