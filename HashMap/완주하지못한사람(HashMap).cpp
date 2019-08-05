//문제 설명
//수많은 마라톤 선수들이 마라톤에 참여하였습니다. 
//단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.
//마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때, 
//완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//Sort를 이용한 Solution
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
//HashMap을 이용한 Solution
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