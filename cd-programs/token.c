#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Enumeration for token types
enum TokenType
{
	KEYWORD,
	IDENTIFIER,
	OPERATOR,
	NUMBER,
	SEMICOLON,
	UNKNOWN
};

// Function to print tokens
void printToken(enum TokenType type, const char *value)
{
	switch (type)
	{
	case KEYWORD:
		printf("<keyword,%s>\n", value);
		break;
	case IDENTIFIER:
		printf("<ID,%s>\n", value);
		break;
	case OPERATOR:
		printf("<%s>\n", value);
		break;
	case NUMBER:
		printf("<number,%s>\n", value);
		break;
	case SEMICOLON:
		printf("<;>\n");
		break;
	case UNKNOWN:
		printf("<Unknown>\n");
		break;
	default:
		break;
	}
}

// Function to tokenize input
void tokenize(const char *input)
{
	char token[100];
	int index = 0;

	for (int i = 0; input[i] != '\0'; ++i)
	{
		if (isalnum(input[i]) || input[i] == '_')
		{
			token[index++] = input[i];
		}
		else if (index > 0)
		{
			token[index] = '\0';

			// Identify token type using a switch-case
			enum TokenType type;
			if (strcmp(token, "int") == 0 || strcmp(token, "char") == 0 || strcmp(token, "float") == 0)
			{
				type = KEYWORD;
			}
			else if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))
			{
				type = NUMBER;
			}
			else if (strlen(token) == 1 && (token[0] == '=' || token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
			{
				type = OPERATOR;
			}
			else if (strlen(token) == 1 && token[0] == ';')
			{
				type = SEMICOLON;
			}
			else
			{
				type = IDENTIFIER;
			}

			// Print the token
			printToken(type, token);

			// Reset the token buffer
			index = 0;
		}
		else if (!isspace(input[i]))
		{
			// Handle single characters as operators
			token[0] = input[i];
			token[1] = '\0';

			// Print the token
			printToken(OPERATOR, token);
		}
	}

	// Handle the last token
	if (index > 0)
	{
		token[index] = '\0';
		printToken(IDENTIFIER, token);
	}
}

int main()
{
	char input[100];

	printf("Enter input: ");
	fgets(input, sizeof(input), stdin);

	printf("Tokens:\n");
	tokenize(input);

	return 0;
}
