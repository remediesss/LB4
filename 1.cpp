#include <iostream>
#include <cstdint>
#include <cstdlib>


struct Node
{
	int data;
	Node* left;
	Node* right;

};

struct Node* root;

struct Node* CreateTree(struct Node* root, struct Node* r, int data)
{
	if (r == NULL)
	{
		r = (struct Node*)malloc(sizeof(struct Node));
		if (r == NULL)
		{
			printf("Îøèáêà âûäåëåíèÿ ïàìÿòè");
			exit(0);
		}

		r->left = NULL;
		r->right = NULL;
		r->data = data;
		if (root == NULL) return r;

		if (data > root->data)	root->left = r;
		else root->right = r;
		return r;
	}

	if (data > r->data)
		CreateTree(r, r->left, data);
	else
		CreateTree(r, r->right, data);

	return root;
}

void print_tree(struct Node* r, int l)
{

	if (r == NULL)
	{
		return;
	}

	print_tree(r->right, l + 1);
	for (int i = 0; i < l; i++)
	{
		printf(" ");
	}

	printf("%d\n", r->data);
	print_tree(r->left, l + 1);
}

bool find_value(Node* root, int value)
{
	if (!root)
	{
		return false;
	}
	else if (root->data == value)
	{
		return true;
	}

	return find_value(root->right, value) || find_value(root->left, value);
}


int main()
{
	setlocale(LC_ALL, "");
	int D, start = 1;

	root = NULL;
	printf("-1 - îêîí÷àíèå ïîñòðîåíèÿ äåðåâà\n");
	while (start)
	{
		printf("Ââåäèòå ÷èñëî: ");
		scanf_s("%d", &D);
		if (D == -1)
		{
			printf("Ïîñòðîåíèå äåðåâà îêîí÷åíî\n\n");
			start = 0;
		}
		else
			root = CreateTree(root, root, D);

	}

	print_tree(root, 0);

	std::cout << "Ââåäèòå ÷èñëî äëÿ ïîñêà: ";
	int value;
	std::cin >> value;
	std::cout << std::endl;


	if (find_value(root, value)) 
	{
		std::cout << "True\n";
	}
	else
	{
		std::cout << "False\n";
	}

	//scanf_s("%d", &D);
	return 0;
}
