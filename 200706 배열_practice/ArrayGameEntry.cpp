#include <string>
#include <iostream>
using namespace std;

class GameEntry //������ ���� ���� ����ϴ� Ŭ����
{
private:
	int score;
	string name;


protected:

public:
	//���� �������� �Լ�
	int getScore() const;

	//�̸� �������� �Լ�
	string getName() const;

	//������- Ŭ���� ��� �����͸� �ʱ�ȭ
	GameEntry(const string& n = "", int s = 0);

	//�Ҹ���- �������� �Ҵ���� �� ��ȯ
};

int GameEntry::getScore() const
{
	return score;
}

string GameEntry::getName() const
{
	return name;
}

//������
GameEntry::GameEntry(const string& n,int s)
	: name(n),score(s) {}


class Scores //���� �������� �迭  entries�� �����ϴ� Ŭ����
{
private:
	int maxEntries; //�迭 �ִ�
	int numEntries; //�迭 ����

	GameEntry* entries; //GameEntry �迭

protected:

public:
	//GameEntry�� �߰��ϴ� �Լ�
	void add(const GameEntry& e);

	//i��° GameEntry�� �����ϴ� �Լ�
	GameEntry remove(int i)
		throw(IndexOutOfBounds); //����ó��

	//������
	Scores(int maxEnt = 10);

	//�Ҹ��� -> �޸� ���� �Ҵ��߱� ������ ��ȯ
	~Scores();
};

//��ü ����
void Scores::add(const GameEntry& e)
{
	int newScore = e.getScore(); //GameEntry�� �߰��� ����

	if (numEntries == maxEntries) //�迭�� �� á��
	{
		if (newScore <= entries[maxEntries - 1].getScore()) //���ο� ������ ���� ������ �����ϱ�
			return;
	}
	else numEntries++; //�� ������ ������, �迭�� �߰� (���� up)

	int i = numEntries - 2; //�߰��� ������ ������ �迭 ĭ ���ʿ��� �����Ѵ�.

	while (i >= 0 && newScore > entries[i].getScore()) //�߰��� ������ ������ �迭 ĭ���� ���� ��
	{
		entries[i + 1] = entries[i];
		i--; //���࿡ �۴ٸ� ���������� �̵�
	}
	entries[i + 1] = e; //�̵��ϰ� ���� �� ������ e �ֱ�
}

//��ü ���� (������� ������ �и��� ���̽�)
GameEntry Scores::remove(int i)
throw(IndexOutOfBounds) //����ó��
{
	if ((i < 0) || (i >= numEntries))
		throw IndexOutOfBounds("Invalid index");

	GameEntry e = entries[i]; //���� ��ü�� �ӽ� ���� e�� ����
	
	for (int j = i + 1; j < numEntries; j++) 
		entries[j - 1] = entries[j]; //�迭 ���� �̵�
	numEntries--; //�迭 �� ���̱�

	return e; //���ŵ� ��ü ��ȯ
}

//������
Scores::Scores(int maxEnt)
{
	maxEntries = maxEnt; //�ִ� ũ�⸦ ����
	entries = new GameEntry[maxEntries]; //�迭 ���� �Ҵ�
	numEntries = 0; //ó������ ���Ұ� ����
}

//�Ҹ���
Scores::~Scores()
{
	delete[] entries;
}