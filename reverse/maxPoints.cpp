/**
 * Definition for a point.
 * struct Point { *     int x; *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */


#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Point{
	public:
		int x; 
		int y;

		Point() : x(0), y(0) {}
		Point(const Point& p): x(p.x), y(p.y){}
		Point(int a, int b) : x(a), y(b) {}

		void setPoint(int x, int y){
			this->x = x;
			this->y = y;
		}


};


class Solution {
	public:
		int maxPoints(vector<Point> &points) {
			int p_size = points.size();

			//if the points is 0 or 1, return 
			if (0 == p_size || 1 == p_size){

				return p_size;
			}

			int max = 0;

			//if the points number larger than 1, find the max number
			for ( int i = 0; i < p_size; i++){

				int maxTemp = 1;
				map <double, int> slopes;
				map <double, int>::iterator it;

				int same = 1;
				int samePoint = 0;
				int p_x = points[i].x;
				int p_y = points[i].y;
				for ( int j = i + 1; j < p_size; j++){
					int delta_x = points[j].x - p_x;
					int delta_y = points[j].y - p_y;


					//if the delta_x == 0, the point in the straight line
					if (0 == delta_x && 0 != delta_y){
						same++;
						continue;

					}else if (0 == delta_x && 0 == delta_y){
						samePoint++;
						continue;
					}else{

						double delta_k = delta_y * 1.0 / delta_x;

						it = slopes.find(delta_k);

						if ( it == slopes.end() ){
							slopes[delta_k] = 2;
						}else{
							slopes[delta_k]++;
						}
					}

				}

				for( it = slopes.begin(); it != slopes.end(); it++){

					if ( it->second > maxTemp ){
						maxTemp = it->second;	
					}
				}

				if( same > maxTemp){
					maxTemp = same;
				}

				maxTemp = samePoint + maxTemp;

				if (maxTemp > max){
					max = maxTemp;
				}

				slopes.clear();

			}

			return max;


		}
};


int main()
{	
	Solution sl;


	struct test{
		int x;
		int y;
	};

	struct test mypoints[] = {{-54,-297},{-36,-222},{3,-2},{30,53},{-5,1},{-36,-222},{0,2},{1,3},{6,-47},{0,4},{2,3},{5,0},{48,128},{24,28},{0,-5},{48,128},{-12,-122},{-54,-297},{-42,-247},{-5,0},{2,4},{0,0},{54,153},{-30,-197},{4,5},{4,3},{-42,-247},{6,-47},{-60,-322},{-4,-2},{-18,-147},{6,-47},{60,178},{30,53},{-5,3},{-42,-247},{2,-2},{12,-22},{24,28},{0,-72},{3,-4},{-60,-322},{48,128},{0,-72},{-5,3},{5,5},{-24,-172},{-48,-272},{36,78},{-3,3}};


	vector<Point> points;

	Point pt(0,0);
	for(int i = 0; i < sizeof(mypoints) / sizeof(mypoints[0]); i++){

		pt.setPoint(mypoints[i].x, mypoints[i].y);
		cout << "add point ("<< mypoints[i].x << "," << mypoints[i].y << ")" << endl;
		points.push_back(pt);

	}

	return 0;

}
