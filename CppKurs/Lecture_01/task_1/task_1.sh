echo 'number of lines:'
wc -l data.dat

echo 'lines with "dolor" or "dalor":'
grep d[a,o]lor data.dat | wc -l

echo 'number of words:'
wc -w data.dat

echo 'number of words starting with "mol"'
grep -c -E "^mol|[[:space:]]mol" data.dat

