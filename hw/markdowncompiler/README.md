# Markdown Compiler Project Overview

Markdown is a language for generating decent formatted text easily. It is typically used to document projects, and has features to compile to HTML.

This file, for example, is written in Markdown, and if you look at raw view  you can see the code.

This document is about a project to extend Markdown substantially and
implement the compiler. This is being done in C++ course, but it can
just as easily be done in Java. Current markdown compilers are
typically in Python, but I do not know python, and in any case, C++
and Java are far faster, and strongly typed which should result in
better error checking.

Here are the subjects in this project

* [Markdown Language Summary](markdowntutorial.md)
* Links to external tutorials on markdown language
  + [w3schools](https://www.w3schools.io/file/markdown-introduction/)
    - [cheatsheet]()
  + [James Bachini](https://jamesbachini.com/markdown-tutorial/)
  + [ItsFOSS](https://itsfoss.com/markdown-guide/)
    - [cheatsheet](https://itsfoss.com/markdown-guide/)
* Markdown turns into HTML, and you can embed HTML and CSS
  + [tutorial on HTML](https://www.w3schools.com/html/)
* The [OpenDSA project](https://opendsa-server.cs.vt.edu/) uses a compiler that also embeds python code; this requires a server running python.
  + [source code for OpenDSA compiler](https://github.com/OpenDSA/OpenDSA)
* [Problems with Markdown as it Exists Today](FixingMarkdown.md)
* TBD: [Proposals for a Markdown Compiler](Compiler.md)
