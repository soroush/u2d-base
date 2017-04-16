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

p = load ('positioning.dat');
errors = sqrt((p(:,7)-p(:,9)).^2+(p(:,8)-p(:,10)).^2);
mean_error = [(p(:,3)+p(:,6))/2  errors];
mean_error = sortrows (mean_error , 1);
subplot (1, 2, 1);
plot(mean_error(:,1), mean_error(:,2), '.r');
title('Distance Estimation Error Model');
xlabel('Mean Distance of Flags (m)');
ylabel('Estimation Error (m)');subplot (1, 2, 2);
plot([1:1:rows(errors)]', sort(errors));
title('Error distribution');
ylabel('Error');
xlabel('No. of Sample (ordered by error)');
