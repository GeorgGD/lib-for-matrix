echo Testing 1500x1500 matrix 
make -s clean

echo ==========================================================
echo Flags = None
make 
time ./lu 1500 0
make -s clean
echo ==========================================================
echo

echo ==========================================================
echo Flags = -O1 -march=native
make -s OFLAGS="-O1 -march=native" 
time ./lu 1500 0
make -s clean
echo ==========================================================
echo

echo ==========================================================
echo Flags = -O2 -march=native
make -s OFLAGS="-O2 -march=native"
time ./lu 1500 0
make -s clean
echo ==========================================================
echo

echo ==========================================================
echo Flags = -O3 -march=native
make -s OFLAGS="-O3 -march=native"
time ./lu 1500 0
make -s clean
echo ==========================================================
echo

echo ==========================================================
echo Flags = -Os -march=native
make -s OFLAGS="-Os -march=native "
time ./lu 1500 0
make -s clean
echo ==========================================================
echo

echo ==========================================================
echo Flags = -O3 -march=native -ffast-math
make -s OFLAGS="-O3 -march=native -ffast-math"
time ./lu 1500 0
make -s clean
echo ==========================================================
echo
