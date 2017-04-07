#  libU2D, Robocup 2D Soccer Server Simulation base of U2D Team.
#
#  Copyright (c) 2016-2017 Soroush Rabiei <rabiei@tidm.net>
#
#  U2D is free software; you can redistribute it and/or
#  modify it under the terms of the GNU Lesser General Public
#  License as published by the Free Software Foundation; either
#  version 2.1 of the License, or (at your option) any later version.
#  See the file COPYING included with this distribution for more
#  information.
#
#  This library is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#  Lesser General Public License for more details.
#
#  You should have received a copy of the GNU Lesser General Public
#  License along with this library; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

pkg load geometry;
intersectingCircles = [];
results = [];
i=0;
while i < 10000
  circles = [52.5-(rand*2*52.5), 34-(rand*2*34), rand*52.5/2, 52.5-(rand*2*52.5), 34-(rand*2*34), rand*52.5/2];
  distance = distancePoints(circles(1:2), circles(4:5));
  if (abs(circles(3)-circles(6)) <= distance && distance <= circles(3)+circles(6))
    intersectionPoints = intersectCircles(circles(1:3), circles(4:6));
    intersectionPoints = reshape(intersectionPoints', 1, numel(intersectionPoints));
    results = [results; circles, intersectionPoints];
    i = i+1;
  endif
endwhile

f = fopen('cc-intersect.h', 'w');
fprintf(f, '%s', "/*\n  libU2D, Robocup 2D Soccer Server Simulation base of U2D Team.\n\
\n\
  Copyright (c) 2016 Soroush Rabiei <rabiei@tidm.net>\n\
\n\
  U2D is free software; you can redistribute it and/or\n\
  modify it under the terms of the GNU Lesser General Public\n\
  License as published by the Free Software Foundation; either\n\
  version 2.1 of the License, or (at your option) any later version.\n\
  See the file COPYING included with this distribution for more\n\
  information.\n\
\n\
  This library is distributed in the hope that it will be useful,\n\
  but WITHOUT ANY WARRANTY; without even the implied warranty of\n\
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU\n\
  Lesser General Public License for more details.\n\
\n\
  You should have received a copy of the GNU Lesser General Public\n\
  License along with this library; if not, write to the Free Software\n\
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA\n*/\n\n");
fprintf(f,"%s","static const float intersects[] = {\n");
fprintf(f, "/*    %11s,%13s,%13s,%13s,%13s,%13s,%13s,%13s,%13s,%13s*/\n","x_0", "y_0", "r_0", "x_1", "y_1", "r_1", "i0_x", "i0_y", "i1_x", "i1_y");
fprintf(f, "    %+e,%+e,%+e,%+e,%+e,%+e,%+e,%+e,%+e,%+e,\n", results' );
fprintf(f, "%s","};\n");
fclose(f);
