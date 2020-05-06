
/** 
 * 863 all-nodes-distance-k-in-binary-tree/
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//�ݹ�ʵ��2 
class Solution2 {
private:
	vector<int> m_data;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    	
    	m_data.clear();
    	dfs(root,target,K);
        return m_data;
    }
    
    //�����root�ڵ㵽target���룬  ����������target�ڵ�. 
    int dfs(TreeNode* root, TreeNode* target, int k)
    {
    	if (NULL == root) return -1;//ȫ�����ұ��ˣ����ҵ��϶�����û����
    	
    	if ( root == target)
    	{   
    		getKNodes(root,k); ////��target ����k��Ԫ����������������
    		return 0; //��target��ʼ����
    	}
    	
        //�ݹ�
    	int left  = dfs(root->left,target,k);
    	int right = dfs(root->right,target,k);
    	
		//target ��������
		if (left >= 0)
		{    
			if (left == k-1 )
		     {
			   m_data.push_back(root->val); //��target ����k��Ԫ�������ĸ����� ��paernt����
		     }
			 
			getKNodes(root->right,k-left-2);//��target ����k��Ԫ�������ĸ����� ��ͬ������
			
			return left +1;
		}
    	//target ����������
    	if (right >= 0)
		{    
			if (right == k-1 )
			{
				m_data.push_back(root->val); 
			
			getKNodes(root->left,k-right-2);
						
			return right +1;
		}
        
    	//target û���ҵ�
    	
    	return -1;
		
    }
    //��ȡ������root�ڵ��k������Ԫ��
    void getKNodes(TreeNode* root,int k)
    {
    	if ( NULL == root || k < 0) return ;
    	if ( 0 == k) m_data.push_back(root->val);
    	
    	getKNodes(root->left,k-1);
    	getKNodes(root->right,k-1);
    }
};

//�ݹ�ʵ��1 �����Ǵ�����룬����ֵ����ȡ��ѵ�� 
class Solution {
private:
	int m_targt;//�ж�targeλ�� left��right
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    	
    	
        
    }
    
    /************************************************* 
    Function:   dfs     
    Description:    �ݹ���� 
    Input:     
    Output:
		isDown
		down���ݹ���ջ��������
		isUP
		up��  �ݹ��ջ��������       
             
    Return:  out
    *************************************************/ 
    void dfs(TreeNode* root, TreeNode* target, int K,bool isDown,int down,bool isUP,int &up,vector<int>& out)
    {
    	if (NULL == root) ;//û���ҵ�Ŀ��ڵ�
    	if (true == isFind) 
    	{
    		down --;
    	}
    	if (root->val == target->val )
    	{
    		isDown = true;
    		down = k;
    	}
    	if (down == 0)
    	{
    		out.push_back(root->val);
    	}
    	
    
		//��·��1��
		//���⣺������ʷ��Ŀ ��tree�ĸ߶ȣ���Ȼÿ���ڵ㿴��root�����ǵ��������root�ǹ̶��Ƚ����ף����������Ŀ����Ϊ����k��һ�����root�� ��ס��
		//�취��д������������ͣ�����ڽ���״̬����������һ������������
		//����ֱ��˼·��ֱ�Ӷ���2�����������ÿ��root�ڵ�ġ�һ���� target-root����m��һ��root��k-n
    	int right =0 ;
    	int left = 0;
    	bool bleft = false;
    	bool bright =false;
    	dfs(root->left,target,K,isDown,bleft,left,out);
    	dfs(root->right,target,K,isDown,bright,right,out);
    	
		//��·��2��д������������ͣ�����ڽ���״̬
    	//�о���д������о��������ˣ������Զ��ˡ�bleft||bright д��һ�鲻�ԣ�ͳһ�������Ϸ��������ʽ������һ���ͱ������£���ס�ˡ�
		//���˼·�ǣ�m_targt���֣�һ���� target-root����m��һ��root��k-n
    	//��m_targt������� ���ؽ��������ط��������ˣ��޷�����
    	    
    	if ( (bleft||bright) && left+right ==k)
    	{
    		out.push_back(root->val);
    		
    	} 
		//��·��3��д������������ͣ�����ڽ���״̬
		//�о����㷵��ֵ�ķ�ʽ�����⡣�����Ҳ�����ν����
    	//����:��������·��������2���������������һ����������أ����������Ǹ��أ�������
    	return isFind || bleft || bright;
    }
};