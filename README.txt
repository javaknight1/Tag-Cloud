The Task

A "tag cloud" is a visual representation of the words which occur most frequently in a document. High frequency words are displayed with larger font sizes and brighter colors. Lower frequency words are displayed with smaller font sizes. The websites www.wordle.net and www.tagcrowd.com generates tag clounds from text that you provide. The website http://chir.ag/phernalia/preztags shows a chronological tag cloud timeline for US Presidential speeches. You assignment is to write a program that tokenizes a text file (reads one "word" at a time) and generates the information required to create a tag cloud.

How does your program work?

Your program prompts the user for the name of the text file to be processed.
Your program reads the text file one "word" at a time and counts the frequency of each word. You should ignore words that are less than 4 characters long and words that contain any non-alphabetic character.
Find the 20 words with the highest frequency counts. If there are fewer than 20 different words, use them all.
Print these 20 words in alphabetical order along with their frequency count. Print each word and its frequency count on a separate line.
 If there are multiple words "tied" as the 20th most frequent word, you may arbitrarily decide which words are not printed.