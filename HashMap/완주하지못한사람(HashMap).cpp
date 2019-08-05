//���� ����
//������ ������ �������� �����濡 �����Ͽ����ϴ�. 
//�� �� ���� ������ �����ϰ�� ��� ������ �������� �����Ͽ����ϴ�.
//�����濡 ������ �������� �̸��� ��� �迭 participant�� ������ �������� �̸��� ��� �迭 completion�� �־��� ��, 
//�������� ���� ������ �̸��� return �ϵ��� solution �Լ��� �ۼ����ּ���.
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//Sort�� �̿��� Solution
string solutionForSort(vector<string> participant, vector<string> completion)
{
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	for (int i=0; i < participant.size()-1; ++i)
	{
		if (participant[i] != completion[i])
			return participant[i];
	}

	return participant[participant.size() - 1];
}
//HashMap�� �̿��� Solution
#include <unordered_map>

string solutionForHash(vector<string> participant, vector<string> completion) 
{
	unordered_map<string, int> stringMap;

	for (auto element : completion)
	{
		if (stringMap.find(element) == stringMap.end())
			stringMap.insert(make_pair(element, 1))
		else
			++stringMap[element];
	}

	for (auto element : participant)
	{
		if (stringMap.find(element) == stringMap.end())
			return element;
		else
		{
			--stringMap[element];
			if (stringMap[element] < 0)
				return element;
		}
	}
}