#include <iostream>
#include <fstream>
#include <regex>

/*
	Tags in html are enclosed in angle brackets <>
	For each tag in properly formed xhtml, there is a matching end tag
	which begins with a forward slash (/)
	<A> </A>
	For example,
  <page>
    <title>AlgeriA</title>
    <id>5</id>
    <revision>
      <id>18063769</id>
      <timestamp>2005-07-03T11:13:13Z</timestamp>
      <contributor>
        <username>Docu</username>
        <id>8029</id>
      </contributor>
      <minor />
      <comment>adding cur_id=5: {{R from CamelCase}}</comment>
      <text xml:space="preserve">#REDIRECT [[Algeria]]{{R from CamelCase}}</text>
    </revision>
  </page>

	Extract all the start tags (not the matching end tags)
	Read in the html file and output a list of the unique tags in the document.
	That is to say, there are many occurrences of each tag

 */
int main() {
	readHTMLFileOutputTags("enwik8");
}
	
