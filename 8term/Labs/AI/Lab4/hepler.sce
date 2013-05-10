x = [0.09 0 0.05];
y = 0.125;

function [res] = f(x)
    n = size(x);
    n = n(2);
    res = [];
    for i = 1:n
        res(i) = 1/(1 + exp(-x(i)));
    end
    res = res';
endfunction

function [res] = f_out(x)
    n = size(x);
    n = n(2);
    res = [];
    for i = 1:n
        res(i) = 1/(1 + exp(-x(i)*0.5));
    end
    res = res';
endfunction

w1 = [ 
-0.582 0.036 0.3
-0.44 -0.956 -0.476
-0.736 0.2 -0.208
-0.878 -0.13 0.382 
0.856 0.876 -0.556
-0.172 -0.292 -0.882
]';

w2 = [
-0.176 0.164 -0.672 -0.918 0.15 -0.462
0.272 -0.996 0.578 0.138 -0.912 -0.686
0.222 0.32 -0.26 0.092 0.154 0.362
0.1 -0.148 -0.56 0.86 -0.228 0.442
]';

w3 = [-0.82 0.24 -0.87 -0.356]';

//res = x * w1 * w2 * w3;

s1 = x * w1 + 1;
y1 = f(s1);
s2 = y1 * w2 + 2;
y2 = f(s2);
s3 = y2 * w3 + 1;
res_y = f_out(s3);

function [res] = f_diff(x)
    n = size(x);
    n = n(2);
    res = [];
    for i = 1:n
        res(i) = exp(x(i))/(1 + exp(-x(i)))^2;
    end
    res = res';
endfunction

dy = y - res_y;
ds2 = dy * w3 .* f_diff(s3)';
ds1 = (ds2' .* f_diff(s2)) * w2';



