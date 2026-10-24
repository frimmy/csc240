---
name: check-transcript
description: >-
  Evaluate a CSC-240 AI Learning Transcript against the course rubric before it's
  uploaded. Use whenever Adrian says "check my transcript", "check the Unit N
  transcript", "does this transcript meet the rubric", "grade my AI transcript",
  or hands over an AI conversation export (PDF/Word) meant for an AI Learning
  Transcript dropbox. Checks the file name, the seed prompt, the exchange count,
  every required element, and the warning signs (AI wrote the structure, STL
  substitution), citing the exchange that satisfies each item. This is a
  verification skill: it never writes, rewrites, or invents transcript content,
  reflections, or summaries.
---

# Check CSC-240 AI Learning Transcript

Evaluate a finished AI conversation against the AI Learning Transcript rubric and report
each item as pass / fail / flag, **citing the exchange number and a short quote** as
evidence. Don't write any part of the transcript for Adrian: no summaries, reflections, or
"suggested replies". A transcript is a record of a real conversation, so the only honest
fix for a missing element is to continue that conversation and re-export. Say which move
would cover the gap, in words.

Last name: **Frimpong**. Source of truth: `csc240/AI_Transcript_Rubric.pdf` ("Learning
with AI — A Practice Run"). The required-elements table is on page 9, and the
example transcript is on pages 10–11. The saved PDF cuts off before section 8 ("Warning
signs") and section 9 ("Before you submit a transcript"). If Adrian adds those, read
them and fold them in.

## Inputs to gather

1. **The transcript file.** It's usually a PDF exported from the chat app (Gemini exports
   label turns `User prompt:` / `Response:`). Word files are allowed too.
2. **The unit number.** Infer it from the folder (`unitN/`) and confirm with Adrian.
3. **The seed prompt.** This is the AI Learning Query from the lab that the *AI Learning
   Transcript Overview* page assigns to his section for that unit. It lives in the lab
   document on D2L, not in this repo, so **ask Adrian to paste it** if it isn't provided.
   Without it, check #3 is ⚠️ "can't verify", not a pass.
4. **(Optional) The submitted lab code** for that lab, used in check #7.

## Procedure

### 1. Extract and split into turns
- PDF: `pdftotext -layout <file> -`. Word: `textutil -convert txt -stdout <file>`.
- If the extracted text is nearly empty, the PDF is screenshots. ❌ fail: the rubric
  asks for the conversation copied as text or exported, because screenshots are hard
  to read.
- Split into alternating student/AI turns using the tool's speaker labels. If the labels
  are ambiguous, show Adrian the split (turn # → first ~10 words) before judging.
- Number them the way the rubric does: **Seed prompt + first answer** (not an exchange),
  then **Exchange 1, 2, 3…**, where one exchange is one student message plus the AI's reply.

### 2. File name
It must be exactly `Unit<N>_AITranscript_Frimpong.pdf` (or `.docx`), with N not zero-padded.
Flag lab-named variants like `AI_Transcript_Lab8_Frimpong.pdf`. Those are named after
the lab, not the unit, and don't match the pattern.

### 3. Seed prompt used as written
The first student message must be the AI Learning Query **exactly as written**. Compare
after normalizing whitespace and smart quotes, and show a word diff of any differences.
Tutor-role text prepended or appended to the query is a ⚠️. The rubric says to put
tutor instructions in learning mode or the tool's custom instructions so the query stays
first and unchanged.

### 4. At least five follow-up exchanges
Count exchanges after the seed. Fewer than 5 is ❌. Note any exchange where the student
message is just an acknowledgement ("thanks", "ok") with no question or claim. It counts
as a message but adds nothing, so flag it as weak.

### 5. Required elements
For each element, name the exchange(s) that satisfy it and quote ≤ 25 words. If none
do, ❌, and name the move that would get there.

| Element (rubric wording) | What to look for | Moves |
| --- | --- | --- |
| Paste your own code and ask about it | A student message containing Adrian's own code (not code the AI just gave him) plus a question about it | 5, 2, Draw it first |
| Something difficult + a **2–3 sentence summary** of what made it click | A topic he struggled with, then a summary **in his own words** of 2–3 sentences. Count the sentences. Flag a summary that paraphrases the AI's wording closely | 3, Ask about cost |
| At least one **pushback** | Adrian tells the AI its answer was wrong, incomplete, or didn't match what his compiler did, **and says why** (ideally with pasted real output). "Are you sure?" alone doesn't count | 4, 2 |
| Closing **reflection** | The final student message covers all three: what he learned, where the tool **helped or misled** him, and **one question he still has**. Check each sub-part separately | Reflection |

### 6. Mix of moves (informational)
Tag each exchange with the move(s) it uses: 1 tutor role, 2 predict-then-run, 3 explain
it back, 4 challenge and verify, 5 feedback on own work, 6 practice without help, plus
Draw it first and Ask about cost. The rubric says "aim for a mix" and "strong transcripts
use most of them". Report the tally. Don't fail on it.

Also classify each student request using the rubric's Activity B labels: *asks for the
answer*, *asks for an explanation*, *asks for practice*, *feedback on my work*,
*challenges or verifies*. A transcript dominated by *asks for the answer* is a ⚠️.

### 7. Warning signs
- **AI wrote the structure.** The AI produced the implementation (a whole class, or the
  core function the lab asks for) instead of asking questions. ⚠️ any substantial AI-written
  code block, and quote its first line. If the lab code is available, grep it for
  distinctive lines from those AI blocks. A match is ❌, because the rubric says such
  code "earns no credit for the work it replaced".
- **STL substitution.** The AI suggested `std::stack`, `std::list`, `std::vector`,
  `std::map`, `std::unordered_map`, etc., for the structure being built. Passes only if
  Adrian **called it out** in the next message. Calling it out is also a strong
  pushback candidate for check #5.
- **AI replies not in full.** The rubric says to paste every AI reply in full. Flag
  replies that look truncated or summarized.
- **Privacy.** Student ID, passwords, personal info, or a classmate's code in the
  conversation is ❌.

## Report format

Lead with an overall verdict: **ready to upload** / **not ready**. Then show a table with
one line per item:

```
#  Check                              Result  Evidence
2  File name                          ❌      AI_Transcript_Lab8_Frimpong.pdf → Unit4_AITranscript_Frimpong.pdf
3  Seed prompt verbatim               ⚠️      seed not provided — can't verify
4  ≥5 follow-up exchanges             ✅      7 exchanges
5a Own code pasted + asked about      ✅      Ex 3: "here's my dequeue…"
...
```

Then show the move tally, and finally a short **"before you upload"** list of the
concrete gaps. Each gap names the move that would close it ("Ex 1–5 have no pushback:
continue the conversation with a Move 4 challenge, then re-export").

Close with the submission reminder: the transcript goes to that unit's **AI Learning
Transcript** folder, which is separate from the lab folder, and it's one per unit.
