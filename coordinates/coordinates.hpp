/*
Copyright 2011 Ángel Olivera Crego
Copyright 2013 Cristian Corado Cordero
Copyright 2017 Alejandro Domínguez Muñoz

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <deque>
#include <cmath>

class polygon {
	private:
		struct vertex {
			double x, y, angle, side_length;
			vertex(double _x, double _y) : x(_x), y(_y), angle(0), side_length(0) {}
			vertex(double _x, double _y, double _angle, double _side_length) : x(_x), y(_y), angle(_angle), side_length(_side_length) {}
		};

		std::deque<vertex> vertices;
		const long double PI = 3.141592653589793115997963468544185161590576171875;
		bool regular;

		int validVertexID(int v);
		double round(double value, int dec);
		vertex nextXYByAngleAndSide(double angle, double side_length, int vertex);
		void setX(double value, int v);
		void setY(double value, int v);
		void setAngle(int v);
		void setAngle(double value, int v);
		void setSideLength(int v);
		void setSideLength(double value, int v);
		void setIsRegular(int v);
		polygon();
	public:
		polygon(double x, double y);
		polygon(double x, double y, double side_length, int sides);

		void newVertexByAxis(double x, double y);
		void newVertexByAngleAndSide(double v_angle, double side_length);
		void close();

		int MaxVertexID();
		double X(int v);
		double Y(int v);
		double Angle(int v);
		double SideLength(int v);
		double Area();
		double Perimeter();
		bool isClosed();
		bool isRegular();
		std::string Name();
		std::string NameIsRegular();
};
