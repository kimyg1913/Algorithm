//���ɽð��� ������ ���, �Ϻ� �л��� ü������ �������߽��ϴ�.
//������ ���� ü������ �ִ� �л��� �̵鿡�� ü������ �����ַ� �մϴ�.
//�л����� ��ȣ�� ü�� ������ �Ű��� �־�, �ٷ� �չ�ȣ�� �л��̳� �ٷ� �޹�ȣ�� �л����Ը� ü������ ������ �� �ֽ��ϴ�.
//���� ���, 4�� �л��� 3�� �л��̳� 5�� �л����Ը� ü������ ������ �� �ֽ��ϴ�.
//ü������ ������ ������ ���� �� ���� ������ ü������ ������ ���� �ִ��� ���� �л��� ü�������� ���� �մϴ�.
//
//��ü �л��� �� n, ü������ �������� �л����� ��ȣ�� ��� �迭 lost, 
//������ ü������ ������ �л����� ��ȣ�� ��� �迭 reserve�� �Ű������� �־��� ��, 
//ü�������� ���� �� �ִ� �л��� �ִ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.
//
//���ѻ���
//��ü �л��� ���� 2�� �̻� 30�� �����Դϴ�.
//ü������ �������� �л��� ���� 1�� �̻� n�� �����̰� �ߺ��Ǵ� ��ȣ�� �����ϴ�.
//������ ü������ ������ �л��� ���� 1�� �̻� n�� �����̰� �ߺ��Ǵ� ��ȣ�� �����ϴ�.
//���� ü������ �ִ� �л��� �ٸ� �л����� ü������ ������ �� �ֽ��ϴ�.
//���� ü������ ������ �л��� ü������ ���������� �� �ֽ��ϴ�.
//�̶� �� �л��� ü������ �ϳ��� �������ߴٰ� �����ϸ�, ���� ü������ �ϳ��̱⿡ �ٸ� �л����Դ� ü������ ������ �� �����ϴ�.

#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) 
{
    set<int> lostSet;
    set<int> reserveSet;
    
    int nowSum = n - lost.size();
    
    for(auto element : lost)
    {
        lostSet.insert(element);
    }
    
    for(auto element : reserve)
    {
        reserveSet.insert(element);
    }
    
    for(auto element : lostSet)
    {
        if(reserveSet.find(element) != reserveSet.end())
        {
            reserveSet.erase(element);
            lostSet.erase(element);
            nowSum++;
        }
    }
    
    for(auto element : reserveSet)
    {
        int before = element - 1;
        int after = element + 1;
        
        if(before > 0)
        {
            if(lostSet.find(before) != lostSet.end())
            {
                nowSum++;
                lostSet.erase(before);
                reserveSet.erase(before);
                continue;
            }
        }
        if(after < n)
        {
            if(lostSet.find(after) != lostSet.end())
            {
                lostSet.erase(after);
                reserveSet.erase(after);
                nowSum++;
                continue;
            }
        }
        
    }
    
    return nowSum;
}