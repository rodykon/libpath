set datafile separator ","
set key autotitle columnhead
set xrange [0:5]
set yrange [0:5]
plot "curves/hermite_quintic.csv" using 1:2 title "Hermite Quintic", \
     "curves/hermite_cubic.csv" using 1:2 title "Hermite Cubic"