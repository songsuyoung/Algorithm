#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int x; // x축을 기준으로 Node 작으면 왼쪽, 크면 오른쪽으로 배치
    int y; //레벨
    int idx;
};

struct Tree
{
    Node* node;
    Tree* left;
    Tree* right;
};

bool compare(Node& node1, Node& node2)
{
    //레벨이 작은 순으로
    if(node1.y == node2.y)
    {
        return node1.x < node2.x;
    }
    
    return node1.y > node2.y;
}

Tree* insert(Tree *tree, vector<Node> &node, const int& idx)
{
    if(tree == nullptr)
    {
        return new Tree{ &node[idx], nullptr, nullptr};
    }
    
    //왼쪽으로 이동 => 
    if(tree->node->x > node[idx].x) //7<4
    {
        tree->left = insert(tree->left, node, idx);
    }
    else
    {
        //오른쪽으로 이동
        tree->right = insert(tree->right, node, idx);
    }
    
    return tree;
}

vector<int> buffer;
//tree print => 3 /전위 순회, 후위 순회, 중위 순회
void preorder(Tree* tree)
{
    if(tree == nullptr)
    {
        return;
    }
    
    buffer.push_back(tree->node->idx);
    preorder(tree->left);
    preorder(tree->right);
}

void postorder(Tree* tree)
{
    if(tree == nullptr)
    {
        return;
    }
    
    postorder(tree->left);
    postorder(tree->right);
    buffer.push_back(tree->node->idx);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    vector<Node> temp;
    for(int i=0; i<nodeinfo.size(); i++)
    {
        temp.push_back({nodeinfo[i][0],nodeinfo[i][1],i+1});
    }
    
    sort(temp.begin(), temp.end(), compare);
    
    //root만 설정하고, 나머지는 이진 탐색으로 위치를 찾아가 부착한다.
    Tree *root = new Tree{&temp[0], nullptr, nullptr};

    for(int i=1; i<temp.size(); i++)
    {
        root = insert(root, temp, i); //1은 level, i는 실제 idx
    }
    
    preorder(root);
    answer.push_back(buffer);
    buffer.clear();
    postorder(root);
    answer.push_back(buffer);
    return answer;
}

/*
길 찾기 게임
카카오 프렌즈를 두 팀으로 나누고, 각 팀이 같은 곳을 다른 순서로 방문하도록 해서 먼저 순회를 마친 팀이 이기는 게임

라이언은 방문할 곳의 2차원 좌표를 각 구하고, 각 장소를 이진트리의 노드가 되도록 구성한 후, 순회 방법을 힌트로 주어 각 팀이 스스로 경로를 찾도록 할 예정

- 레벨 => y
- 트리 번호 => x

예)
전위 순회 : 7, 4, 6, 9, 1, 8, 5, 2, 3
후위 순회 : 9, 6, 5, 8, 1, 4, 3, 2, 7


즉, x,y에 대해서 tree를 생성해서 전위 순회 후위 순회를 도는 함수를 만드는 문제

1. 구조체로 만들기
y => 레벨 (y값이 작은게 루트에 더 가까움)
x => 왼쪽/오른쪽 순서 (x값이 작은게 왼쪽 서브트리일 확률이 높음)
idx => 번호 1번부터 차례대로 넣기
    => 차례대로 못넣는 이유가 x값은 V의 x값보다 크다. (즉 이분 탐색을 사용해서 x값 비교후 삽입하는 코드가 필요할 듯)
    
2. 정렬을 수행해서, 각 개수에 따라 트리의 노드를 붙인다.

예) 

하나의 큰 반복문 두고 => 트리 삽입할 개수 N의 개수는 미리 지정해도 되지만, 실제 레벨은 logN + 1의 값을 가진다.
즉, 9개 개수에 대해서 log 9 => 5레벨

삽입 개수 2^n
tree[0].push(정렬된 첫번째 idx)
tree[1].push_back() => 1개 / 1개
2개 2개
4개 4개

2^n씩 증가함.

*/