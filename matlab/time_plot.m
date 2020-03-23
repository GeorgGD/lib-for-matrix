clear
clc

data = readtable('./before_opt_perf.txt');
y = data{:,1};
x = data{:,2};

data = readtable('./omp_opt_perf.txt');
y1 = data{:,1};
x1 = data{:,2};

data = readtable('./Oflag_opt_perf.txt');
y2 = data{:,1};
x2 = data{:,2};

data = readtable('./Oflag_omp_opt_pref.txt');
y3 = data{:,1};
x3 = data{:,2};

plot(x,y, '*',x1,y1,'*', x2,y2,'*',x3,y3,'*');
title('Plot of run-time for N-size matrix');
xlabel('Size of matrix');
ylabel('Run time (seconds)');
grid on;
