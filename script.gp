set terminal postscript "Helvetica" 24 color eps enhanced
# set terminal x11
set xlabel "Time"
set ylabel "D.C."
set nokey
set xrange[0:]
set yrange[-0.2:1.1]
set nokey
set out 'results.eps'

set style line 1 lc 1 lt 1 lw 3 pt 1 ps 1.0
plot "results.dat" using 1:2 with linespoints linestyle 1