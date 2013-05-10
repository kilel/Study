function [out]=getTStat(x, y)
     
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
     s2 = ESS/(n-k);
     s = sqrt(s2); 
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



n = 15;
k = 5;


x =  [1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;
1961 1962 1963 1964 1965 1966 1967 1968 1969 1970 1971 1972 1973 1974 1975 1976 1977 1978 1979 1980 1981 1982 1983 1984 1985 1986 1987 1988 1989 1990 1991 1992 1993 1994 1995
]';

y = [ 35.2 37.6 40.8 44.8 49.6 53.6 57.6 63.2 76 93.6 103.2 116.8 132.8 163.2 167.2 188.8 205.6 224.8 262.4 292.8 324 344.8 360 398.4 439.2 418.4 421.6 472 535.2 589.6 620 633.6 629.6 668 709.6 ]';

 
 ///
 t = size(x);
 n = t(1);
 k = t(2) - 1;
 b = (x'*x)^(-1)*x'*y;

 e = x * b - y;
 dw = 0; 
 for i = 2:n do dw = dw + (e(i) - e(i-1))^2; end; 
 dw = dw/(e'*e);
 
 brx = ones(n-1, 1);
 brx(:,2) = e(2:n);
 bry = e(1:n-1);
 bbr = (brx'*brx)^(-1)*brx'*bry;
 b_tstat = getTStat(brx, bry);

 qstat = n*(n+2)*bbr(2)^2/(n-1);
 
 
 darx = ones(n-1, 1);
 darx(:, 2) = x(1:n-1,2); 
 darx(:, 3) = y(2:n);
 
 dary = y(1:n-1);
 darb = (darx'*darx)^(-1)*darx'*dary;
 dart = getTStat(darx, dary);
 
 orkcnt = 1;
 orkr = bbr(2);
     while 1==1 do
     orkx = x(1:n-1, :) - orkr*x(2:n,:); 
     orkx(:, 3) = y(2:n);
     orky = y(1:n-1);
     orkb = (orkx'*orkx)^(-1)*orkx'*orky;
     orkcnt = orkcnt+ 1;
     if orkcnt > 100 then break; end
     if abs(orkr - orkb(3)) < 0.001 then  break; end;
     orkr = orkb(3);
 end
 
 omnkx = x(1:n-1, :) - darb(3)*x(2:n,:);
 omnkx(:, 1) = omnkx(:, 1) + darb(3)*y(2:n);
 omnky = y(1:n-1);
 omnkb = (omnkx'*omnkx)^(-1)*omnkx'*omnky;
 omnkn = n-1;
 
 ////
 ///
 //
 
 
 //spirman
 tx = omnkx(:, 2); //x1
 ty = abs(omnkx*omnkb - omnky)
 p_spirman = 0;
 for i = 1:omnkn do
     p_spirman = p_spirman + (getRank(tx, tx(i)) - getRank(ty, ty(i)))^2;
 end
 p_spirman =  p_spirman*6 / (omnkn^3 - omnkn);
 t_spirman = abs(p_spirman)*sqrt(n-2)/(1 - p_spirman^2);
 t_spirman_krit = 2.144;   
 spirman_significent = t_spirman > t_spirman_krit;     
 
 //
 tx1 = omnkx(1:n/3 ,:);
 ty1 = omnky(1:n/3);
 tx2 = omnkx(2*n/3:n, :);
 ty2 = omnky(2*n/3:n);
 goldfeldt_F = getESS(tx1, ty1)/ getESS(tx2, ty2);
 goldfeldt_krit = 2.2
 goldfeldt_is_geter = goldfeldt_F > goldfeldt_krit;
 
 //
 
 omnke = omnky - omnkx*omnkb;
 tx = omnkx;
 tx(:, 2) = tx(:, 2).*tx(:, 2);
 white_F = getFStat(tx, omnke);
 //
 
 best = -1;
 besti = -1;
 omnke = abs(omnky - omnkx*omnkb);
 for gam = 1:10
     tx =  omnkx(:, 1);
     tx(:, 2) = omnkx(:, 2)^gam; // x3
     temp = getTStat(tx, omnke);
     temp = temp(2)
     if temp > best then
         best = temp;
         besti = gam;
     end
     tx(:, 2) = omnkx(:, 2)^(1/gam); // x3
     temp = getTStat(tx, omnke);
     temp = temp(2)
     if temp > best then
         best = temp;
         besti = 1/gam;
     end
 end
 
 tx  = omnkx(:, 1);
 tx(:, 2) = omnkx(:, 2)^besti; // x3
 glaizer_f = getFStat(tx, omnke);
 
 sigma_eps =  sqrt(tx*((tx' * tx)^(-1) * tx' * omnke ));
 omnk2x = omnkx(:, 1) ./ sigma_eps;
 omnk2x(:, 2) = omnkx(:, 2) ./ sigma_eps;
 
 ////
 
 omnk2b = (omnk2x'*omnk2x)^(-1)*omnk2x'*omnky;
 
 
 