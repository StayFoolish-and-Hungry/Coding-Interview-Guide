//
//构造数组的MaxTree
//不重复的数组，数组元素个数,时间复杂度Ｏ（ｎ），空间复杂度Ｏ（ｎ）
#include <iostream>
#include <vector>
#include <stack>
#include "BiTree.h"

using namespace std;

vector<int> getMaxTree(int arr[], int n)
{
    vector<int> res(n, -1);
    stack<int> st;
    for (int i =0; i < n ; i++)
    {
        while(!st.empty() && arr[i] > arr[st.top()])
        {
            if (arr[i] < arr[res[st.top()]] || res[st.top()] == -1)
                res[st.top()] = i;
            st.pop();

        }
        if (!st.empty())
        {
            res[i] = st.top();
        }
        st.push(i);
    }
    return res;
}

BiTree* buildTreeNode(vector<int> res, int arr[], int n)//返回的是根节点，即head节点
{
    if(res.empty())
        cout << "数组为空，请重新输入！!";
    TreeNode *head = NULL;
    vector<TreeNode> Node(n);

    for (int i = 0; i < n; i++)
    {
        if (Node[arr[i]-1].getValue() == 0)//节点位置从０开始计数，即位置０存储节点１
        {
            Node[arr[i]-1].setValue(arr[i]);
        }
        if (res[i] != -1)
        {
            if (Node[arr[res[i]] - 1].getLchild() == NULL)
            {
                Node[arr[res[i]] - 1].setLchild(&Node[arr[i] - 1]);
            }
            else if (Node[arr[res[i]] - 1].getLchild()->getValue() > arr[i])
            {
                int tmp = Node[arr[res[i]] - 1].getLchild()->getValue();
                Node[arr[res[i]] - 1].setLchild(&Node[arr[i] - 1]);
                Node[arr[res[i]] - 1].setRchild(&Node[tmp - 1]);
            }
            else
                Node[arr[res[i]] - 1].setRchild(&Node[arr[i] - 1]);
        }
        else
        {
            head = &Node[arr[i]-1];
        }

    }
    return head;
}

int main()
{
    
    return 0;
}
