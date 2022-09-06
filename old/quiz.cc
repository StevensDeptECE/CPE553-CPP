/*
A question container is a chunk of document containing a number of elements together comprising a question

Instructions: should generate the following html:
<p class="inst">Instructions for the question</p>

There can also be other dynamic components to questions including:

Image (display a picture in the middle of the question) html:
<img class="mcimage" src="1234.jpg">
<img src="circuit123.png">
<img src="circuit123.svg">

video: display a video clip in the question. Typically the user would
be expected to watch the video and answer something pertaining to the
video. <videoplayer src="mymovie.mp4"></videoplayer>

sound: same as video, different tag

Questions are the actual input that capture the information from the user.
The following type of questions are supported:

Fill in the blank. User types in an answer, which is compared on the server. There could be more than one correct answer, and the string match must be exact.
For example, if the correct answer is "abc" and the user types "abc " or "ABC" the answer is incorrect.
<input type="test" name="q1_1"/>

Fill in the blank Case insensitive
Exactly like fill in the blank but "ABC" and "abc" are both correct

Fill in the blank space insensitive
Exactly like fill in the blank but "abc" and "abc " " abc" "a bc" are all equiavalent.

Tokenized Fill in the blank
Exactly like fill in the blank designed for answers where spaces matter only in some contexts.
where the answer is "public static void"  "public     static void"  but not "pub lic static void"

Regex
Exactly like fill in the blank but the answer is specified as a regular expression. if the regex matches the text, the question is correct

Essay: A human has to grade this component of the quiz.
<textarea class="essay" name="q1_1">default value of text here</textarea>

Code: should generate an html textarea to allow typing code. With a button that compiles. The user should see the results from the compilation. The server is ofcourse beyond the scope of this problem.
<textarea class="code" name="q1_1">default value of text here</textarea>
<button class="ctrl" value="Compile"/>
<textarea class="code" readonly>output from compiler should be placed here</textarea>


diagram:
A diagram question is where the diagram is the answer to the question.
This would require a javascript engine editing diagrams

Multiple choice
MultipleChoiceHorizontal
What is 2 + 2?
a) 3   b) 4   c) 5  d) not enough information to determine

MultipleChoiceVertical
What is 2 + 2?
a) 3
b) 4
c) 5
d) not enough information to determine

Dropdown (use a dropdown list)


MultipleAnswerHorizontal
MultipleAnswerVertical


Define Complexity    O(n),O(log n),O(n log n), O(n^2), ...
Allow predefining answers

A Quiz is a collection of questionContainers

or

A Quiz has 1 or more sections
Each section has 1 or more questionContainers
selected randomly from question pools


When a question is answered, there is a response
printing a message
playing a sound
playing a video
link to a document
*/
