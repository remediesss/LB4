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
			printf("Ошибка выделения памяти");
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

int getLevel(Node* root, int target, int level) {
	if (root == nullptr) {
		return -1;
	}

	if (root->data == target) {
		return level;
	}

	int leftLevel = getLevel(root->left, target, level + 1);
	if (leftLevel != -1) {
		return leftLevel;
	}

	return getLevel(root->right, target, level + 1);
}

int main()
{
	setlocale(LC_ALL, "");
	int D, start = 1;

	root = NULL;
	printf("-1 - окончание построения дерева\n");
	while (start)
	{
		printf("Введите число: ");
		scanf_s("%d", &D);
		if (D == -1)
		{
			printf("Построение дерева окончено\n\n");
			start = 0;
		}
		else
			root = CreateTree(root, root, D);

	}

	print_tree(root, 0);

	std::cout << "Введите число для поска: ";
	int value;
	std::cin >> value;
	std::cout << std::endl;


	if (find_value(root, value))
	{
		std::cout << "True\n";
		std::cout << "Level = " << getLevel(root, value, 1) << std::endl;

	}
	else
	{
		std::cout << "False\n";
	}

	return 0;
}
