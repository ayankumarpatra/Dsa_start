#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

#define ll long long

class Solution
{
public:
    ll side;
    int k;
    ll mapTo1D(vector<int> &p)
    {
        int x = p[0], y = p[1];

        if (y == 0)
            return x;

        if (x == side)
            return side + y;

        if (y == side)
            return 3 * side - x;

        return 4 * side - y;
    }

    bool isPossible(int d, vector<ll> &distances)
    {
        int n = distances.size() / 2;
        for (int i = 0; i < n; i++)
        {
            int leftPoint = i, rightPoint = n + i - 1;
            int firstPoint = leftPoint; // taken as first point
            int currPoint = firstPoint;

            for (int cnt = 1; cnt <= k; cnt++)
            {
                if (cnt == k)
                    if (((distances[firstPoint + n]) - distances[currPoint]) >= d)
                        return true;
                    else
                        break;

                ll currDist = distances[currPoint];
                ll targetDist = currDist + d;

                int l = currPoint + 1, r = rightPoint, ans = -1;
                while (l <= r)
                {
                    int mid = l + (r - l) / 2;
                    if (distances[mid] >= targetDist)
                    {
                        ans = mid;
                        r = mid - 1;
                    }
                    else
                        l = mid + 1;
                }
                if (ans == -1)
                    break;
                currPoint = ans;
            }
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>> &points, int k)
    {
        this->side = side;
        this->k = k;

        vector<ll> distances;
        for (int i = 0; i < points.size(); i++)
            distances.push_back(mapTo1D(points[i]));

        sort(distances.begin(), distances.end());

        int n = distances.size();
        vector<ll> extDistances(2 * n);
        for (int i = 0; i < n; i++)
        {
            extDistances[i] = distances[i];
            extDistances[i + n] = distances[i] + (4LL * side);
        }

        int l = 0, r = side, ans = 0;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (isPossible(mid, extDistances))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }

        return ans;
    }
};


int main (){

    
    return 0;
}