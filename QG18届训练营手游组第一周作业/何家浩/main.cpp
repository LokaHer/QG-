#include"main.h"
using namespace std;
int k = 0;

void say1()
{
	cout << "�����ǵ�������" << endl;
	cout << "��q������ǰ����һ���ڵ�" << endl << "��wɾ��������ǰ�Ľڵ�" << endl << "��e����������һ���ڵ�" << endl;
	cout << "��rɾ���������Ľڵ�" << endl << "��t������ĵ�n��Ԫ��ǰ����Ԫ��" << endl << "��yɾ������ڵ�" << endl;
	cout << "��uɾ�����нڵ�" << endl << "��i��ѯԪ�ش治����" << endl << "��o��ѯ����Ԫ������" << endl;
	cout << "��p���������ÿ��Ԫ�ص���visitָ��ĺ���" << endl << "��a��ת����" << endl << "��s��ѯ�����Ƿ�ɻ�" << endl;
	cout << "��dż�ڵ㷴ת����" << endl << "��f��ѯ�м�ڵ�" << endl;
	cout << "�ǳ���лʦ�������Ը���ҵŶ" << endl << "ǿ���Ƽ�ʦ�����ظ���Σ���e�����ּӻس�����һ���϶�ڵ������" << endl;
	cout << endl;
}
void say2()
{
	cout << "������˫������" << endl;
	cout << "��q������ǰ����һ���ڵ�" << endl << "��wɾ��������ǰ�Ľڵ�" << endl << "��e����������һ���ڵ�" << endl;
	cout << "��rɾ���������Ľڵ�" << endl << "��t������ĵ�n��Ԫ��ǰ����Ԫ��" << endl << "��yɾ������ڵ�" << endl;
	cout << "��uɾ�����нڵ�" << endl << "��i��ѯԪ�ش治����" << endl << "��o��ѯ����Ԫ������" << endl;
	cout << "��p���������ÿ��Ԫ�ص���visitָ��ĺ���" << endl;
	cout << "�ǳ���лʦ�������Ը���ҵŶ" << endl << "ǿ���Ƽ�ʦ�����ظ���Σ���e�����ּӻس�����һ���϶�ڵ������" << endl;
	cout << endl;
}





int main()
{
	system("color F0");
	cout << "��ѡ��������1��or˫������2��" << endl;
	int x=0;
	while (1 != scanf_s("%d", &x) || x < 1 || x > 2)
	{
		cout<<"�����������룡"<<endl;
		while (getchar() != '\n');
	}
	if (x == 1)
	{
		danLB d1;
		int temp=0;
		unsigned int index;
		say1();
		while (true)
		{
			char a = _getch();
			if (a == 'q')
			{
				cout << "��������ͷ����ӵĽڵ�dataŶ��int���ͣ�" << endl;
				while (1 != scanf_s("%d", &temp))
				{
					cout << "�����������룡"<<endl;
					while (getchar() != '\n');
				}
				d1.push_front(temp);
			}
			if (a == 'w')
			{
				d1.pop_front();
			}
			if (a == 'e')
			{
				cout << "��������β����ӵĽڵ�dataŶ��int���ͣ�" << endl;
				while (1 != scanf_s("%d", &temp))  
				{
					cout << "�����������룡" << endl;
					while (getchar() != '\n');
				}
				d1.push_back(temp);
			}
			if (a == 'r')
			{
				d1.pop_back();
			}
			if (a == 't')
			{
				cout << "���ڵ�n��Ԫ��ǰ����Ԫ�أ�������n��n����Ϊ1Ŷлл��" << endl;
				int i = 0;
				for (d1.p1 = d1.head; d1.p1 != nullptr; i++)d1.p1 = d1.p1->next;//��ڵ���Ŀ
				while (1 != scanf_s("%d", &index)||(int)index < 2|| (int)index > i)
				{
					cout << "�����������룡" << endl;
					while (getchar() != '\n');
				}
				cout << "������ýڵ������Ŷ��int���ͣ�" << endl;
				while (1 != scanf_s("%d", &temp))
				{
					cout << "�����������룡" << endl;
					while (getchar() != '\n');
				}
				d1.insert(index, temp);
			}
			if (a == 'y')
			{
				
				while (d1.p1 != nullptr)
				{
					d1.p1 = d1.p1->next;
					k++;
				}
				d1.p1 = d1.head;
				cout << "����������ɾ���Ľڵ�" << endl;
				while (1 != scanf_s("%d", &index)|| (int)index>k|| (int)index<1)
				{
					cout << "�����������룡" << endl;
					while (getchar() != '\n');
				}
				d1.erase(index);
			}
			if (a == 'u')
			{
				d1.clear();
			}
			if (a == 'i')
			{
				cout << "������������ҵ��Ǹ��治���ڵ�Ԫ��" << endl;
				while (1 != scanf_s("%d", &temp))
				{
					cout << "�����������룡" << endl;
					while (getchar() != '\n');
				}
				if (d1.contain(temp))
				{
					cout << "���ڣ�����" << endl;
					_getch();
				}
				else
				{
					cout << "�����ڣ�����" << endl;
					_getch();
				}
			}
			if (a == 'o')
			{
				cout << "����Ԫ������Ϊ" << d1.size() << endl;
				_getch();
			}
			if (a == 'p')
			{
				d1.traverse(d1.prints);	
				_getch();
			}
			if (a == 'a')
			{
				d1.reverse();
			}
			if (a == 's')
			{
				if (d1.isLoop())
				{
					cout << "��������ڻ�������" << endl;
					_getch();
				}
				else
				{
					cout << "������û�л�������" << endl;
					_getch();
				}
			}
			if (a == 'd')
			{
				d1.reverseEven();
			}

			if (a == 'f')
			{
				d1.middleElem();
			}
			d1.show();
		}
	}
	if (x == 2)
	{
		
		shuangLB d2;
		int temp;
		unsigned int index;
		say2();
		while (true)
		{
			char a = _getch();
			if (a == 'q')
			{
				cout << "��������ͷ����ӵĽڵ�dataŶ��int���ͣ�" << endl;
				while (1 != scanf_s("%d", &temp))
				{
					cout << "�����������룡" << endl;
					while (getchar() != '\n');
				}
				d2.push_front(temp);
			}
			if (a == 'w')
			{
				d2.pop_front();
			}
			if (a == 'e')
			{
				cout << "��������β����ӵĽڵ�dataŶ��int���ͣ�" << endl;
				while (1 != scanf_s("%d", &temp))
				{
					cout << "�����������룡" << endl;
					while (getchar() != '\n');
				}
				d2.push_back(temp);
			}
			if (a == 'r')
			{
				d2.pop_back();
			}
			if (a == 't')
			{
				cout << "���ڵ�n��Ԫ��ǰ����Ԫ�أ�������n��n����Ϊ1Ŷлл��" << endl;
				while (1 != scanf_s("%d", &index))
				{
					cout << "�����������룡" << endl;
					while (getchar() != '\n');
				}
				cout << "������ýڵ������Ŷ��int���ͣ�" << endl;
				while (1 != scanf_s("%d", &temp))
				{
					cout << "�����������룡" << endl;
					while (getchar() != '\n');
				}
				d2.insert(index, temp);
			}
			if (a == 'y')
			{

				while (d2.p1 != nullptr)
				{
					d2.p1 = d2.p1->next;
					k++;
				}
				d2.p1 = d2.head;
				cout << "����������ɾ���Ľڵ�" << endl;
				while (1 != scanf_s("%d", &index) || (int)index > k || (int)index < 1)
				{
					cout << "�����������룡" << endl;
					while (getchar() != '\n');
				}
				d2.erase(index);
			}
			if (a == 'u')
			{
				d2.clear();
			}
			if (a == 'i')
			{
				cout << "������������ҵ��Ǹ��治���ڵ�Ԫ��" << endl;
				while (1 != scanf_s("%d", &temp))
				{
					cout << "�����������룡" << endl;
					while (getchar() != '\n');
				}
				if (d2.contain(temp))
				{
					cout << "���ڣ�����" << endl;
					_getch();
				}
				else
				{
					cout << "�����ڣ�����" << endl;
					_getch();
				}
			}
			if (a == 'o')
			{
				cout << "����Ԫ������Ϊ" << d2.size() << endl;
				_getch();
			}
			if (a == 'p')
			{
				d2.traverse(d2.prints);
				_getch();
			}
			d2.show();
		}
	}
	system("pause");
	return 0;
}