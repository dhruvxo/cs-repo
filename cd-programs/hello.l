%{
    #include<stdio.h>
    int i=0;
%}

%%
([a-zA-Z0-9])* {printf("Identifier\n");}
                {printf("%s\n",yytext);}
%%
int main()
{
    yylex();
    return 0;
}