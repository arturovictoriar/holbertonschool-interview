#include "substring.h"

#define INDEX(x) ((x) - 'a')

/**
 * free_chance - frees all nodes of chance
 * @root: pointer to root
 */
void free_chance(Chance *root)
{
	int i = 0;

	for (i = 0; i < 26; i++)
		if (root->children[i])
			free_chance(root->children[i]);
	free(root);
}

/**
 * search_chance - searches chance for word
 * @node: root of tree
 * @str: string to find
 * @k: characters of str to find
 * @memo: the memoization array
 * @j: index in memo
 * Return: 1 if found else 0
 */
int search_chance(Chance *node, char *str, int k, Chance **memo, int j)
{
	for (; k; str++, k--)
	{
		if (!node->children[INDEX(*str)])
			return (0);
		node = node->children[INDEX(*str)];
	}

	memo[j] = node;
	if (node->left-- > 0)
	{
		return (1);
	}
	return (0);
}

/**
 * make_chance - fills chance with words
 * @root: pointer to root of chance
 * @words: pointer to array of words
 * @nb_words: number of words
 * @nodes: array of chance nodes to populate
 */
void make_chance(Chance *root, char const **words, int nb_words,
	Chance **nodes)
{
	int i = 0;
	char const *str;
	Chance *node;

	for (i = 0; i < nb_words; i++)
	{
		node = root;
		for (str = words[i]; *str; str++)
		{
			if (!node->children[INDEX(*str)])
			{
				node->children[INDEX(*str)] = calloc(1, sizeof(Chance));
				if (!node->children[INDEX(*str)])
					exit(1);
			}
			node = node->children[INDEX(*str)];
		}
		node->word = 1;
		node->count++;
		node->left++;
		node->val = (char *)words[i];
		nodes[i] = node;
	}
}
/**
 * find_substring - finds substring composed of all concatenated words
 * @s: the string to search
 * @words: array of contentated words to find
 * @nb_words: the size of passed array
 * @n: size of return array, to set
 * Return: array of indices where all words found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int i = 0, j = 0, k = 0, slen = 0, matches = 0, *indices = NULL;
	Chance *root = NULL, **nodes = NULL, **memo = NULL;

	*n = 0;
	slen = strlen(s), k = strlen(words[0]);

	indices = calloc(slen, sizeof(int)), root = calloc(1, sizeof(Chance));
	nodes = calloc(nb_words, sizeof(*nodes)), memo = calloc(slen, sizeof(*memo));

	if (!indices || !root || !nodes || !memo)
		exit(1);

	make_chance(root, words, nb_words, nodes);

	for (i = 0; i < slen; i++)
	{
		matches = 0;
		for (j = i; j <= slen - k; j += k)
		{
			if ((memo[j] && memo[j]->left-- > 0) ||
				search_chance(root, (char *)s + j, k, memo, j))
			{
				if (++matches == nb_words)
				{
					indices[*n] = i;
					*n += 1;
					break;
				}
			}
			else
				break;
		}
		for (j = 0; j < nb_words; j++)
			nodes[j]->left = nodes[j]->count;
	}
	free_chance(root), free(nodes), free(memo);
	if (*n == 0)
		indices = (free(indices), NULL);
	return (indices);
}
