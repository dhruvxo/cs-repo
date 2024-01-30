%{
void yyerror(char*);
%}
start	"/*"
mid		[\*|.]*[^\*\n\/]*
end		"*/"
newline	\n
comms	{start}({mid}{newline}?)*{end}
%%
"//".*	printf("single line comment\n");
{comms}	printf("multi\n");

