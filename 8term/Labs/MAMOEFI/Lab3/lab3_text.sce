n = 69;
k = 8;

x = [
[1, 1, 1, 50.7, 15.4, 8.2, 0, 1, 0, 15.9];
[1, 3, 1, 88.9, 31.2, 10.7, 0, 1, 0, 27.0];
[1, 1, 1, 45.2, 12.3, 10.7, 0, 1, 12, 13.5];
[1, 1, 1, 50.7, 15.4, 8.5, 0, 1, 12, 15.1];
[1, 2, 1, 71.1, 21.5, 10.7, 0, 1, 12, 21.1];
[1, 3, 1, 97.1, 35.6, 10.7, 0, 1, 12, 28.7];
[1, 3, 1, 93.2, 35.3, 10.7, 0, 0, 0, 27.2];
[1, 3, 1, 96.9, 36.5, 10.4, 0, 0, 0, 28.3];
[1, 4, 1, 179.0, 67.1, 14.6, 0, 1, 0, 52.3];
[1, 1, 1, 52.0, 13.6, 11.0, 1, 1, 8, 22.0];
[1, 2, 1, 68.9, 23.9, 10.0, 1, 1, 8, 28.0];
[1, 3, 1, 111.8, 37.5, 14.0, 1, 1, 8, 45.0];
[1, 4, 1, 127.4, 50.6, 13.0, 1, 1, 8, 51.0];
[1, 2, 1, 81.4, 16.5, 11.0, 1, 1, 0, 34.4];
[1, 1, 1, 58.9, 15.8, 10.4, 1, 1, 8, 24.7];
[1, 2, 1, 73.3, 22.8, 9.4, 0, 1, 8, 30.8];
[1, 1, 1, 48.1, 13.7, 8.3, 0, 1, 0, 15.9];
[1, 3, 1, 87.8, 33.5, 8.3, 0, 1, 0, 29.0];
[1, 1, 1, 48.1, 13.7, 8.3, 0, 1, 3, 15.4];
[1, 3, 1, 89.7, 32.6, 8.3, 0, 1, 3, 28.6];
[1, 1, 1, 52.0, 15.4, 8.3, 0, 0, 0, 15.6];
[1, 3, 1, 89.8, 31.8, 8.3, 0, 1, 0, 27.7];
[1, 2, 1, 88.5, 27.2, 13.0, 1, 1, 20, 34.1];
[1, 2, 1, 97.9, 31.8, 12.1, 1, 1, 20, 37.7];
[1, 3, 1, 108.8, 37.3, 12.1, 1, 1, 20, 41.9];
[1, 1, 1, 63.3, 17.2, 12.4, 1, 1, 20, 24.4];
[1, 1, 1, 51.9, 13.8, 8.1, 1, 0, 0, 21.3];
[1, 2, 1, 89.2, 27.3, 17.0, 1, 1, 12, 36.7];
[1, 1, 1, 50.7, 15.4, 9.2, 1, 0, 0, 21.5];
[1, 2, 1, 63.2, 23.8, 8.0, 1, 0, 0, 26.4];
[1, 3, 1, 127.4, 43.1, 22.0, 1, 0, 0, 53.9];
[1, 2, 1, 89.1, 23.6, 8.3, 1, 1, 6, 34.2];
[1, 2, 1, 92.4, 27.8, 13.3, 1, 1, 6, 35.6];
[1, 3, 1, 88.4, 31.5, 8.0, 1, 1, 12, 34.0];
[1, 1, 1, 49.4, 14.6, 7.4, 1, 1, 12, 19.0];
[1, 2, 1, 121.2, 38.1, 14.0, 1, 1, 12, 46.6];
[1, 3, 1, 152.1, 42.5, 25.0, 1, 1, 12, 58.5];
[1, 1, 2, 54.6, 16.2, 10.2, 1, 0, 12, 24.2];
[1, 2, 2, 80.6, 26.9, 11.0, 1, 0, 12, 35.7];
[1, 3, 2, 115.7, 40.2, 11.5, 1, 1, 12, 51.2];
[1, 4, 2, 171.6, 68.9, 11.0, 1, 1, 12, 75.9];
[1, 1, 2, 53.0, 14.8, 10.1, 1, 1, 6, 21.2];
[1, 2, 2, 77.0, 24.5, 11.2, 1, 1, 6, 30.8];
[1, 3, 2, 85.0, 29.9, 9.3, 1, 1, 6, 34.0];
[1, 2, 2, 78.3, 27.9, 10.9, 1, 1, 12, 31.9];
[1, 3, 2, 106.9, 38.2, 13.8, 1, 1, 12, 43.6];
[1, 3, 2, 127.9, 40.2, 15.3, 1, 1, 12, 52.2];
[1, 3, 3, 99.7, 34.4, 8.0, 1, 1, 0, 43.1];
[1, 1, 3, 50.3, 15.4, 10.2, 1, 1, 6, 25.0];
[1, 2, 3, 73.3, 25.2, 10.1, 1, 1, 6, 35.2];
[1, 3, 3, 99.7, 34.4, 8.0, 1, 1, 6, 40.8];
[1, 1, 3, 50.3, 15.4, 10.2, 1, 0, 0, 18.2];
[1, 1, 3, 54.0, 15.4, 10.2, 1, 1, 0, 20.1];
[1, 2, 3, 63.4, 21.9, 8.0, 1, 0, 0, 22.7];
[1, 2, 3, 74.6, 25.8, 10.1, 1, 1, 0, 27.6];
[1, 3, 3, 99.7, 34.4, 8.0, 0, 1, 0, 36.0];
[1, 1, 4, 48.1, 13.5, 8.3, 0, 1, 7, 17.8];
[1, 2, 4, 70.2, 23.5, 8.3, 0, 1, 7, 25.9];
[1, 3, 4, 88.4, 32.7, 8.3, 0, 1, 7, 32.6];
[1, 1, 4, 52.7, 12.3, 11.0, 0, 1, 3, 19.8];
[1, 2, 4, 79.3, 23.8, 11.0, 0, 1, 3, 29.9];
[1, 3, 4, 104.0, 35.1, 11.0, 1, 1, 3, 39.2];
[1, 1, 4, 67.6, 16.3, 11.2, 1, 1, 18, 22.4];
[1, 2, 4, 101.5, 30.8, 11.6, 1, 1, 18, 35.2];
[1, 3, 4, 119.1, 41.4, 16.0, 0, 0, 18, 41.2];
[1, 1, 4, 51.9, 14.8, 8.4, 0, 1, 6, 17.8];
[1, 2, 4, 73.1, 24.2, 11.1, 0, 1, 6, 25.0];
[1, 3, 4, 102.8, 32.6, 15.5, 0, 1, 6, 35.2];
[1, 4, 4, 119.1, 42.5, 9.4, 0, 1, 6, 40.8]
 ];
 //task 1;
 y = x(:,k+2);
 x = x(:,1:(k+1));
 
 ///model definition
 x(:, 8:9) = [];
 x(:, 5:6) = [];
 x(:, 2) = [];
 ///
 t = size(x);
 n = t(1);
 k = t(2) - 1;
 b = (x'*x)^(-1)*x'*y;
 //task 2
 temp_y = x*b - y;
 ESS = temp_y'*temp_y;
 avg_y = (y'*ones(n,1))/n;
 temp_y = x*b - avg_y;
 RSS = temp_y'*temp_y;
 TSS = RSS + ESS;
 R2 = 1 - ESS/TSS
 R2_korr = 1 - (n-1)/(n-k-1)*(1-R2);
 
 //task 3
 s2 = ESS/(n-k);
 s = sqrt(s2); 
 s2R = TSS/(k-1);
 //task 4
 avg_x = (ones(1,n)*x/n);
 temp_avg_x = x;
 for i = 1:n
     temp_avg_x(i,:) = temp_avg_x(i, :) - avg_x;
 end
 temp_x = 1:(k+1);
 for i = 1:(k+1)
     temp_x(i) = temp_avg_x(:, i)'*temp_avg_x(:, i);
 end
 temp_x = sqrt(temp_x);
 s_beta2 = diag((x'*x)^-1);
 
 t_stat_b = abs(b./sqrt(s_beta2)/s);
 t_krit = 2.001;
 b_not_null = t_stat_b > t_krit;
 
 //task 5
 F_model =  R2/(1-R2) * (n-k-1)/(k);
 F_krit = 3.053;
 model_not_bad = F_model > F_krit;
 
 //task 6
 b_min_val_abs = t_krit * sqrt(s_beta2) * s;
 
 //task 7
 Dx = ones(1,n) * (x.*x)/n - avg_x.*avg_x;
 Dy = sum(y.*y)/n - avg_y^2;
 r_xx = zeros(k, k);
 for i = 2:(k+1)
     for j = 2:(k+1)
         temp_avg_x1x2 = sum(x(:, i).*x(:, j))/n - avg_x(i)*avg_x(j)  ;
         //disp(temp_avg_x1x2);
         r_xx(i-1,j-1) = temp_avg_x1x2/sqrt(Dx(i)*Dx(j));
     end
 end
 
 r_xy = zeros(1,k);
 for i = 2:(k+1)
    temp_avg_xy = sum(x(:, i).*y)/n - avg_x(i)*avg_y;
    r_xy(i-1) = temp_avg_xy /sqrt(Dy * Dx(i));
 end    
 
 //task 8
 r_private = zeros(k,1);
 for i = 2:(k+1)
     //mnk y, x without x[i]
     // mnk x[i] from all x's
     //korr between them
     temp_x = x;
     temp_x(:, i:i) = [];
          temp_korr = y;
     temp_b = (temp_x' * temp_x)^(-1) * temp_x' * temp_korr;
     temp_y1 = temp_x * temp_b - temp_korr;
     //
     temp_korr = x(:,i);
     temp_b = (temp_x' * temp_x)^(-1) * temp_x' * temp_korr;
     temp_y2 = temp_x * temp_b - temp_korr;
     //
     temp_korr = temp_y1' * temp_y2/n  - sum(temp_y1)*sum(temp_y2)/n/n;
     D1 = temp_y1' * temp_y1/n  - sum(temp_y1)*sum(temp_y1)/n/n;
     D2 = temp_y2' * temp_y2/n  - sum(temp_y2)*sum(temp_y2)/n/n;
     r_private(i-1) = temp_korr/sqrt(D1*D2);
 end
 
 
 
 
 function [rankor] = getRank(vect, val)
     eps = 0.001;
     k = size(vect);
     n = k(2) * k(1);
     vect = gsort(vect);
     for i = 1:n
         if abs(vect(i) - val) < eps then
             j = i+1;
             try
             while abs(vect(j) - val) < eps do j = j + 1;
             end
         catch
             end
             j = j-1;
             rankor = (j+i)/2.;
             break;
         end
         rankor = -1;
     end
     
 endfunction
 
 function [ESS] = getESS(x, y)
     t = size(x);
     n = t(1);
     k = t(2) - 1;
     b = (x'*x)^(-1)*x'*y;
     temp_y = x*b - y;
     ESS = temp_y'*temp_y;
 endfunction
 
 function [model_F] = getFStat(x,y)
     t = size(x);
     n = t(1);
     k = t(2) - 1;
     b = (x'*x)^(-1)*x'*y;
     temp_y = x*b - y;
     ESS = temp_y'*temp_y;
     avg_y = (y'*ones(n,1))/n;
     temp_y = x*b - avg_y;
     RSS = temp_y'*temp_y;
     TSS = RSS + ESS;
     R2 = 1 - ESS/TSS
     R2_korr = 1 - (n-1)/(n-k-1)*(1-R2);
     model_F =  R2/(1-R2) * (n-k-1)/(k);
 endfunction
 
 function [outArray]=sort(data, sortCol)
     outArray = [];
     cnt = 1;
     while 1 > 0 do
         s = size(data);
         s = s(1);
         if s == 0 then break; end
         Max = data(1, sortCol);
         maxi = 1;
         for i = 1:s
             if  Max < data(i, sortCol) then
                 Max = data(i, sortCol);
                 maxi = i;
             end
         end
         outArray(cnt, :) = data(maxi, :);
         cnt = cnt + 1;
         data(maxi, :) = [];
     end
 endfunction
 
 function [out]=getTStat(x, y, numCol)
     
     t = size(x);
     n = t(1);
     k = t(2) - 1;
     b = (x'*x)^(-1)*x'*y;
     temp_y = x*b - y;
     ESS = temp_y'*temp_y;
     avg_y = (y'*ones(n,1))/n;
     temp_y = x*b - avg_y;
     RSS = temp_y'*temp_y;
     TSS = RSS + ESS;
     R2 = 1 - ESS/TSS
     R2_korr = 1 - (n-1)/(n-k-1)*(1-R2);
     
     //task 3
     s2 = ESS/(n-k);
     s = sqrt(s2); 
//     s2R = TSS/(k-1);
     //task 4
     avg_x = (ones(1,n)*x/n);
     temp_avg_x = x;
     for i = 1:n
         temp_avg_x(i,:) = temp_avg_x(i, :) - avg_x;
     end
     temp_x = 1:(k+1);
     for i = 1:(k+1)
         temp_x(i) = temp_avg_x(:, i)'*temp_avg_x(:, i);
     end
     temp_x = sqrt(temp_x);
     s_beta2 = diag((x'*x)^-1);
     
     t_stat_b = abs(b./sqrt(s_beta2)/s);
     out = t_stat_b;
     
 endfunction 

 //spirman
 tx = x(:, 3); //x3
 ty = abs(x*b - y)
 p_spirman = 0;
 for i = 1:n do
     p_spirman = p_spirman + (getRank(tx, tx(i)) - getRank(ty, ty(i)))^2;
 end
 p_spirman =  p_spirman*6 / (n^3 - n);
 t_spirman = abs(p_spirman)*sqrt(n-2)/(1 - p_spirman^2);
 t_spirman_krit = t_krit;   
 spirman_significent = t_spirman > t_spirman_krit;     
 
 //
 x_orig = x;
 //
 tx = x;
 tx(:, 5) = y - x*b;
 tx = sort(tx, 5);
 x = tx;
 x(:, 5) = [];
 tx1 = x(1:n/3 , :);
 ty1 = y(1:n/3);
 tx2 = x(2*n/3:n, :);
 ty2 = y(2*n/3:n);
 goldfeldt_F = getESS(tx1, ty1)/ getESS(tx2, ty2);
 goldfeldt_krit = 2.2
 goldfeldt_is_geter = goldfeldt_F > goldfeldt_krit;
 
 //
 x = x_orig;
 
 b = (x'*x)^(-1)*x'*y;
 e = y - x*b;
 tx = x(:, 2)^2; // x2
 tx(:, 2 ) = x(:, 3)^2 // x3
 tx(:, 3 ) = x(:, 3).*x(:, 2) // x2x3
 white_F = getFStat(tx, e);
 
 //
 
 best = -1;
 besti = -1;
 b = (x'*x)^(-1)*x'*y;
 e = abs(y - x*b);
 for gam = 1:50
     tx =  x(:, 1);
     tx(:, 2) = x(:, 3)^gam; // x3
     temp = getTStat(tx, e, 2);
     temp = temp(2)
     if temp > best then
         best = temp;
         besti = gam;
     end
     tx(:, 2) = x(:, 3)^(1/gam); // x3
     temp = getTStat(tx, e, 2);
     temp = temp(2)
     if temp > best then
         best = temp;
         besti = 1/gam;
     end
 end
 
 tx =  x(:, 1);
 tx(:, 2) = x(:, 3)^besti; // x3
 glaizer_f = getFStat(tx, e);
 
 //
 
 sigma_eps2 =  tx*((tx' * tx)^(-1) * tx' * e );
 x(:, 3) = x(:, 3)  ./ sqrt(sigma_eps2);
 x(:, 1) = x(:, 1)  ./ sqrt(sigma_eps2);
 x(:, 2) = x(:, 2)  ./ sqrt(sigma_eps2);
 x(:, 4) = x(:, 4)  ./ sqrt(sigma_eps2);
 
 ////
 ///
 ///
 ///
 ///
 
 t = size(x);
 n = t(1);
 k = t(2) - 1;
 b = (x'*x)^(-1)*x'*y;
 //task 2
 temp_y = x*b - y;
 ESS = temp_y'*temp_y;
 avg_y = (y'*ones(n,1))/n;
 temp_y = x*b - avg_y;
 RSS = temp_y'*temp_y;
 TSS = RSS + ESS;
 R2 = 1 - ESS/TSS
 R2_korr = 1 - (n-1)/(n-k-1)*(1-R2);
 
 //task 3
 s2 = ESS/(n-k);
 s = sqrt(s2); 
 s2R = TSS/(k-1);
 //task 4
 avg_x = (ones(1,n)*x/n);
 temp_avg_x = x;
 for i = 1:n
     temp_avg_x(i,:) = temp_avg_x(i, :) - avg_x;
 end
 temp_x = 1:(k+1);
 for i = 1:(k+1)
     temp_x(i) = temp_avg_x(:, i)'*temp_avg_x(:, i);
 end
 temp_x = sqrt(temp_x);
 s_beta2 = diag((x'*x)^-1);
 
 t_stat_b = abs(b./sqrt(s_beta2)/s);
 t_krit = 2.001;
 b_not_null = t_stat_b > t_krit;
 
 //task 5
 F_model =  R2/(1-R2) * (n-k-1)/(k);
 F_krit = 3.053;
 model_not_bad = F_model > F_krit;
 
 //task 6
 b_min_val_abs = t_krit * sqrt(s_beta2) * s;
 
 //task 7
 Dx = ones(1,n) * (x.*x)/n - avg_x.*avg_x;
 Dy = sum(y.*y)/n - avg_y^2;
 r_xx = zeros(k, k);
 for i = 2:(k+1)
     for j = 2:(k+1)
         temp_avg_x1x2 = sum(x(:, i).*x(:, j))/n - avg_x(i)*avg_x(j)  ;
         //disp(temp_avg_x1x2);
         r_xx(i-1,j-1) = temp_avg_x1x2/sqrt(Dx(i)*Dx(j));
     end
 end
 
 r_xy = zeros(1,k);
 for i = 2:(k+1)
    temp_avg_xy = sum(x(:, i).*y)/n - avg_x(i)*avg_y;
    r_xy(i-1) = temp_avg_xy /sqrt(Dy * Dx(i));
 end    
 
 //task 8
 r_private = zeros(k,1);
 for i = 2:(k+1)
     //mnk y, x without x[i]
     // mnk x[i] from all x's
     //korr between them
     temp_x = x;
     temp_x(:, i:i) = [];
          temp_korr = y;
     temp_b = (temp_x' * temp_x)^(-1) * temp_x' * temp_korr;
     temp_y1 = temp_x * temp_b - temp_korr;
     //
     temp_korr = x(:,i);
     temp_b = (temp_x' * temp_x)^(-1) * temp_x' * temp_korr;
     temp_y2 = temp_x * temp_b - temp_korr;
     //
     temp_korr = temp_y1' * temp_y2/n  - sum(temp_y1)*sum(temp_y2)/n/n;
     D1 = temp_y1' * temp_y1/n  - sum(temp_y1)*sum(temp_y1)/n/n;
     D2 = temp_y2' * temp_y2/n  - sum(temp_y2)*sum(temp_y2)/n/n;
     r_private(i-1) = temp_korr/sqrt(D1*D2);
 end
 
 
 
 