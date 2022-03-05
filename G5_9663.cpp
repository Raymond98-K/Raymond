#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

//�ð����� 10��???? ��Ϳ� �ݺ��� ������ ����..?
//���� ������ ���ذ� �ȵż� �׳� N-Queen�� �˻��� ���� �����ߴ�.
//���� ��� 8*8 ü���ǿ� �� 8���� ���´�. 
//�̶� �� � ���� �ٸ� ���� ���� ��ο� ��ġ�� �ʰ� ��ġ�ϴ� ����� ���� ���ϸ� �ȴ�.
//�˻�� ����, �밢���� check�ϰ� ���࿡ ��ģ�ٸ� ������Ȳ���� ���ư��� ��Ʈ��ŷ ���
//��ǥ�� ����ؾ��ϴ� ���ߺ��͸� ����� �ϸ� �ȴ�.
//------------------------------------------------------------------
//���ߺ��ͷ� �ϴ� 10�ʸ� �׳� �Ѿ �ٸ� ������� ���� �ʿ�
//�밢���� ����� üũ�ϰ� �����ٿ� ���� �Ѱ� �̻� ������ �� ���� ������ �����ٿ� ���� �˻�� pass
//�������� ���������Ƿ� ���� ���ߺ��͸� ������� �ʾƵ� �ȴ�.

void isNQueen(vector<int> chess, int checker, int N);  
//��Ʈ��ŷ �Լ�. checker�� ���� üũ���� ���� ��ȣ �̴�.

int answer = 0;  //���������� ��µ� ��

int G5_9663(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int intN;
	cin >> intN;

	vector<int> chessBoard(15);  
	//���� ��ġ�� ��ϵ� ����. �ε����� ���� ��ȣ, ��Ҵ� ���� ��ȣ
	//ex [0] = 1 �̶�� (0,1) ��, ù��° ���� 1��(�ι�°) ���� ���� �ִٴ� ��

	isNQueen(chessBoard, 0, intN);  //�Լ� ȣ��. checker�� �ʱⰪ�� 0�̸� intN�� �Բ� �Ѱ��ش�.

	cout << answer;  //�� ���

	return 0;
}



void isNQueen(vector<int> chess, int checker, int N)
{
	if (checker == N)  //���� ���� ���� intN = N�� ���ٸ�(��� ���� �� �˻��ߴٸ�)
	{
		answer++;  //����� �� 1 �߰�

		return;  //����
	}

	//�װ� �ƴ϶�� �ش� �࿡ ���� �˻� ����
	for (int i = 0; i < N; ++i)
	{
		chess[checker] = i;  //�ش� ��(checker)�� i��° ���� ���� ���� ����.
		int isAttacked = 0;  //��ģ Ƚ��. 1�̻��̶�� ��� �ϳ� �̻��� ���� ��ΰ� ��ģ�ٴ� ���̴�.

		for (int j = 0; j < checker; ++j)  //���� ������ ��(checker)���� �������� �˻��Ѵ�.
		{
			//������ ���� ��ġ�� ���� �迭 ������ �Ұ����ϴ� ���� �밢���� ��ġ�� �ʴ��� �˻��Ѵ�.
			//���� ���� ������ ĭ�� ���ݱ��� ������ �� ���� ��Ұ� ���� ��� ���� ��ġ�Ƿ� �����Ѵ�
			//���� �� ���� (��-��) ���� (��-��) ���� ���밪�� ���� ��� �밢���� ��ġ�Ѱ��̹Ƿ� �����Ѵ�.

			if ((chess[checker] == chess[j]) || (abs(checker - j) == abs(chess[checker] - chess[j])))
			{
				//���� ������ �����Ѵٸ� �̹� ������ ���� ��ΰ� ��ģ�ٴ� ���̴�.
				isAttacked++;  //���� ��ģ Ƚ���� ������Ų��.

				break;  //������ �ݺ��� �ǹ̰� �����Ƿ� �˻縦 �����Ѵ�.
			}

		}

		if (isAttacked == 0)  //�����˻簡 ���� �� ��ģ Ƚ���� 0�̶��
		{
			isNQueen(chess, checker + 1, N);  //���Ƶ� �Ǵ� ���� ���Ҵٴ� ���̹Ƿ� ���� ������ �Ѿ �ݺ��Ѵ�.
		}

	}
	
}