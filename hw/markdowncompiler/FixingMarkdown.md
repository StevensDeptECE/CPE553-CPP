# What is Missing in Markdown?

## Variables

Variables are needed so that a location can be defined once and used all over a document. For example, if referring to locations on a web page, it is extremely valuable to be able to construct relative URIs.

For example: github.com/stevensdeptece/CPE-553hw is the base URL. This makes the text both shorter and more maintainable.

## Including Files

If multiple files need the same text or the same variable definitions, an obvious way of doing this is including a file with the common information

## Functions or Macros

It is possible that including files is too coarse-grained, after all
if you want two lines that are commonly used, you don't want to have
to have a file just for that. This leads to some kind of function call
mechanism.


Proposals for a new markdown standard:

Note that the proposals here are for the *kind* of changes I want, not the specific syntax. The primary design question is how to design a language that is easy to type text in, yet when you want to program easy to do that in. You need an escape character. LaTeX uses backslash to show commands.
Markdown uses backtick \` for some things, Pound sign (hash sign) \# for others.

What we need here is some fresh ideas, some design creativity.
Look at the examples in this directory, come up with ideas, then once your ideas are coherent, a parser can be written to parse the language.

Look at [LaTeX](example.tex)

Look at this file, but also look at the markdown tutorials.

Look at the document for the [LiquiZ specification](https://docs.google.com/document/d/1xA5tcTj2O3x6TE-iLzpi9GMdwuGl94tpXGmiJIJzVPA/edit?usp=sharing)
It documents what we did to create interactive quizzes, which I want embedded into a new markdown.

```cpp
def x 1.5		// double
def y 2345		// integer, default should be signed/unsigned/size?
def z 1.5_f32		// full rust style typed constants?
def abc "string"
def 
include(file)		//
eqn(\int{}Ae^x)         // LaTeX inside
img(image.jpg)
img(image.jpg,"caption text")
table(['First Name%20s', 'Last Name%20s', 'Age%3d'],[])
quote("He lives everywhere in mathematics.", "E.T. Bell *Men of Mathematics*")
figure(drawing)
figure(drawing, "caption text")
link(text,url)
link(url)
anchor(name, text)
citation()
image(url)
video(url)
quiz(id)
code(id)

form(name) {
input(name)
option(name)
}

// a stretch goal is to produce a formatting language that can define rectangular regions and format them. Markdown doesn't do much in this regard.
box() {

}

grid(style) {
}
//strongly typed or
fn funcname(params) {

}

```