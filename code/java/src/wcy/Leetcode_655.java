package wcy;

import java.util.ArrayList;
import java.util.List;
import java.lang.Math;

public class Leetcode_655 {

	public List<List<String>> printTree(TreeNode root) {
		// 1.���root�ĸ߶�
		int rows = getHeight(root);
		// 2.������List�Ŀ��
		int cols = (int) (Math.pow(2.0, rows) - 1);

		// �Խ������ʼ��
		List<List<String>> res = new ArrayList<>(rows); // vector

		for (int i = 0; i < rows; i++) {
			List<String> list = new ArrayList<>();
			for (int j = 0; j < cols; j++) {
				list.add("");
			}
			res.add(list);
		}
		// 3.ǰ������������ڽ�����������������Ȼ�����������
		dfs(root, 0, 0, cols - 1, res);
		return res;

	}

	private void dfs(TreeNode root, int level, int start, int end, List<List<String>> res) {

		if (root == null || start > end) {
			return;
		}

		int mid = (start + end) / 2;

		res.get(level).set(mid, Integer.toString(root.val));
		
		//�ݹ��ӡ������
		dfs(root.left,level+1,start,mid-1,res);
		//�ݹ��ӡ������
		dfs(root.right,level+1,mid+1,end,res);
		
		

	}

	private int getHeight(TreeNode root) {
		if (root == null) {
			return 0;
		}

		return Math.max(getHeight(root.left), getHeight(root.right)) + 1;
	}

}
