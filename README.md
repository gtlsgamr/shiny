# SHINY - An HTML to GemText converter 💎 
------------------------------------
NOTE: This is a work in progress.
------------------------------------
At this point, the program assumes a few things:
* You will not nest tags on the same line.
* You will start anchor tag attributes with the href attribute:
	```
	<a href=""..... > </a>   <---- Correct    
	<a class="" href=""..... > </a>   <---- Correct    
	```
* One type of tag on one line, if possible.
* Try to keep <br> tags on seperate lines.
* Try to avoid <strong> <emphasis> <b> <i> tags inline if possible.
* You will enter html without meta data. It might work with it, but try to input only the stuff that you want to convert and nothing else.
