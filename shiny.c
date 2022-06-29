/*	
	SHINY - An HTML to GemText converter
	====================================
WIP: Please provide suggestions to:
gtlsgamr<gtlsgamr@tilde.team> or 
gtlsgamr<gtlsgamr@ctrl-c.club>  
====================================
At this point, the program assumes a few things:
 * You will not nest tags on the same line.
 * You will start anchor tag attributes with the href attribute:
 <a href=""..... > </a>   <---- Correct
 <a class="" href=""..... > </a>   <---- Correct
 * One type of tag on one line, if possible.
 * You will enter html without meta data. It might work with it, but try to input only the stuff that you want to convert and nothing else.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int in_tag=0;

void gettag(char *S);
void tagparser(char *tag);
void parser();

int main(int argc, char * argv[]) {
	parser();
	return 0;
}

void gettag(char *S){
	int c,i=0;
	while((c=getchar())!=' ' && c!='>'){
		if(c=='/')return;
		*(S+i)=c;
		i++;
	}
	*(S+i)='\0';
}

void tagparser(char *tag) {
	in_tag=1;
	int c=getchar();

	if(strcmp(tag,"a")==0){
		printf("\n=> ");
		for(;(c!=39&&c!='"');c=getchar());
		c=getchar();
		for(;c!=39 && c!='"';c=getchar()){
			printf("%c",c);
		}
		for(;c!='>';c=getchar());
		printf(" ");
		for(c=getchar();c!='<';c=getchar()){
			printf("%c",c);
		}
		for(;(c!='>');c=getchar());
		printf("\n");
	}

	if(strncmp(tag,"h",1)==0){
		switch(tag[1]){
			case '1': printf("# "); 
					  break;
			case '2': printf("## "); 
					  break;
			case '3': printf("### "); 
					  break;
			case '4': printf("### "); 
					  break;
			case '5': printf("### "); 
					  break;
			case '6': printf("### "); 
					  break;
			default : break;
		}
		for(;c!='<';c=getchar()){
			printf("%c",c);
		}
		for(;(c!='>');c=getchar());
		printf("\n");

	}

	if(strcmp(tag,"p")==0){
		printf("%c",c);
		for(c=getchar();c!='<';c=getchar()){
			printf("%c",c);
		}
		for(;(c!='>');c=getchar());
		printf("\n");
	}

	in_tag=0;
}

void parser() {
	int c,d;
	char *curr_tag;
	curr_tag = (char *)malloc(sizeof(char)*8);
	while ((c = getchar()) != EOF) {
		if(c=='\n'){
			printf("%c",c);
			d = getchar();
			while(isspace(d)){
				d=getchar();
			}
			if(d=='<' && in_tag==0){
				gettag(curr_tag);
				tagparser(curr_tag);
			}
			else{
				printf("%c",d);
			}

			parser();
		}
		else if(c=='<' && in_tag==0){
			gettag(curr_tag);
			tagparser(curr_tag);
		}
		else{
			printf("%c",c);
		}
	}
}
