
using System;
using System.Collections.Generic;
using System.Text;


namespace lab3_tr
{
    class trans
    {
        private
            int n, m, fictive;
            string log;
            List<int> seller, customer;
            List<List<int>> cost, weight;
            List<int> h, v; //покрытия
            List<int> gr, qs;
            List<int> gout, gin;
           
        
        // // // /// / / // / ///
            void create_wei(int meth)
            {
                
                weight = new List<List<int>>(n);
                for (int i = 0; i < n; i++)
                    weight.Add( new List<int>(m));
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < m; j++)
                        weight[i].Add(0);
                gr = new List<int>();
                qs = new List<int>();
                List<int> h, w;
                h = new List<int>(seller);
                w = new List<int>(customer);
                int t = 0, t1 = 0;
                
                /*SortedList<int, int> sl = new SortedList<int, int>();
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < m; j++)
                        sl.Add(cost[i][j], i * m + j);*/
                List<int> sl, tt;
                sl = new List<int>();
                tt = new List<int>();
                for (int i = 0; i < n * m; i++)
                {
                    tt.Add(cost[i / m][i % m]);
                    sl.Add(i);
                }
                for (int i = 0; i < n * m; i++)
                {
                    int min = tt[i], mini = i;
                    for (int j = i; j < n * m; j++)
                        if (tt[j] < min)
                        {
                            min = tt[j];
                            mini = j;
                        }
                    int tmp = sl[mini];
                    sl[mini] = sl[i];
                    sl[i] = tmp;
                    tt[mini] = tt[i];
                    tt[i] = min;
                }

                if (meth == 1)
                {//simple
                    for (int i = 0; i < n; i++)
                        for (int j = 0; j < m; j++)
                        {
                            t = Math.Min(h[i], w[j]);
                            if (t > 0)
                            {
                                gr.Add(i * m + j);
                                h[i] -= t;
                                w[j] -= t;
                                weight[i][j] += t;
                            }
                        }
                }
                else
                {//optimized
                    for (int j = 0; j < n * m; j++)
                    {
                        int i = sl[j];
                        t = Math.Min(h[i / m], w[i % m]);
                        if (t > 0)
                        {
                            gr.Add(i);
                            h[i/m] -= t;
                            w[i%m] -= t;
                            weight[i/m][i%m] += t;
                        }
                    }
                }
                t = 0; t1 = 0;
                foreach (int l in h) t += l;
                foreach (int l in w) t1 += l;
                
                if (t < t1)
                {
                    fictive = 1;
                    seller.Add(t1 - t);
                    cost.Add(new List<int>(m));
                    weight.Add(new List<int>(m));
                    for (int i = 0; i < m; i++)
                    {
                        cost[n].Add(0);
                        weight[n].Add(0);
                        if (w[i] > 0)
                        {
                            weight[n][i] = w[i];
                            gr.Add(n * m + i);             //114121825
                        }
                    }
                    n++;
                }
                else if (t > t1)
                {
                    fictive = -1;
                    customer.Add(t - t1);
                    for (int i = 0; i < n; i++)
                    {
                        cost[i].Add(0);
                        weight[n].Add(0);
                        if (h[i] > 0)
                        {
                            weight[i][m] = h[i];
                            gr.Add(i * m + i);             //114121825
                        }
                    }
                    m++;
                }
                if (gr.Count < n + m - 1)
                { 
                    for(int i = 0; i < m*n; i++)
                        if (!gr.Contains(sl[i]))
                        {
                            gr.Add(sl[i]);
                            if (gr.Count == m + n - 1)
                                break;
                        }
                }
                
            }
            void create_list()
            {
                gout = new List<int>();
                gin = new List<int>();
                qs = new List<int>();
                /*for (int i = 0; i < n + m - 1; i++)
                {
                    qs.Add(gr.Count);
                    for (int j = gr[i]/m - 1; j >= 0; j--)  //добавить первую видимую по строкам
                        if(gr.Contains(j*m+gr[i]%m))
                        {
                            gout.Add(i);
                            gin.Add(j * m + gr[i] % m);
                            break;
                        }
                    for (int j = gr[i] / m + 1; j < n; j++)
                        if (gr.Contains(j * m + gr[i] % m))
                        {
                            gout.Add(i);
                            gin.Add(j * m + gr[i] % m);
                            break;
                        }

                    for (int j = gr[i] % m - 1; j >= 0; j--)
                        if (gr.Contains(j + gr[i] / m))
                        {
                            gout.Add(i);
                            gin.Add(j + gr[i] / m);
                            break;
                        }
                    for (int j = gr[i] % m + 1; j < m; j++)
                        if (gr.Contains(j + gr[i] / m))
                        {
                            gout.Add(i);
                            gin.Add(j + gr[i] / m);
                            break;
                        }
                    
                }
                qs.Add(gr.Count);
                */

                for (int i = 0; i < gr.Count; i++)
                {
                    qs.Add(gin.Count);
                    for (int j = 0; j < gr.Count; j++)
                    {
                        if (i == j)
                            continue;
                        if (gr[i] % m == gr[j] % m || gr[i] / m == gr[j] / m)
                        {
                            gout.Add(i);
                            gin.Add(j);
                        }

                    }
                }
                qs.Add(gin.Count);
            }
            int teta()
            {
                int maxi=0, ma = int.MaxValue;
                
                h = new List<int>(m);
                v = new List<int>(n);
                for (int i = 0; i < m; i++)
                    h.Add(int.MinValue);
                for (int j = 0; j < n; j++)
                    v.Add(int.MinValue);
                int c = 0, t = 0;
                v[0] = 0;
                while(true)
                {
                    c = 0;
                    t = 0;
                    for (int i = 0; i < n; i++)
                        if (v[i] > int.MinValue)
                        {
                            for (int j = 0; j < m; j++)
                                if (gr.Contains(i * m + j))
                                    h[j] = cost[i][j] - v[i];
                        }
                        else c++;
                     for (int j = 0; j < m; j++)
                        if (h[j] > int.MinValue)
                        {
                            for (int i = 0; i < n; i++)
                                if (gr.Contains(i * m + j))
                                    v[i] = cost[i][j] - h[j];
                        }
                        else t++;
                     if (c == 0 && t == 0)
                         break;
                }
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < m; j++)
                        if (cost[i][j] - h[j] - v[i] < ma)
                        {
                            ma = cost[i][j] - h[j] - v[i] ;
                            maxi = i * m + j;
                        }
                if (ma >= 0)
                    return -1;
                return maxi;
            }
            void move(int t)
            {
                gr.Add(t);
                create_list();
                List<int> cyc = cycle(gr.Count-1,0);
                log += "\nНайден цикл:\n";
                for (int i = 0; i < cyc.Count; i++)
                {
                    log += "(" + (gr[cyc[i]] / m) + ", " + (gr[cyc[i]] % m) + ")";
                    if (i != cyc.Count - 1)
                        log += " -> ";
                }
                int min = weight[gr[cyc[1]] / m][gr[cyc[1]] % m], mini = 1 ;
                for (int i = 1; i < cyc.Count; i+=2)
                    if (min > weight[gr[cyc[i]] / m][gr[cyc[i]] % m])
                    {
                        min = weight[gr[cyc[i]] / m][gr[cyc[i]] % m];
                        mini = i;
                    }
                for (int i = 0; i < cyc.Count; i += 2)
                {
                    weight[gr[cyc[i]] / m][gr[cyc[i]] % m] += min;
                    if(i+1 < cyc.Count)
                        weight[gr[cyc[i + 1]] / m][gr[cyc[i + 1]] % m] -= min;
                }
                gr.RemoveAt(cyc[mini]);
            }
            List<int> cycle(int t, int shift)
            {
                List<int> from = new List<int>(gr.Count);
                List<int> cyc = new List<int>();
                Queue<int> q = new Queue<int>();
                List<int> used = new List<int>();
                int now;
                for (int i = 0; i < gin.Capacity; i++)
                    used.Add(0);
                for (int i = 0; i < gr.Count; i++)
                    from.Add(-1);
                now = gin[qs[t]+shift];
                used[now] = 1;
                from[now] = t;

                for (int i = qs[now]; i < qs[now + 1]; i++)
                    if (gin[i] != t &&
                        gr[gin[i]] % m != gr[from[now]] % m &&
                        gr[gin[i]] / m != gr[from[now]] / m)
                    {
                        q.Enqueue(gin[i]);
                        used[gin[i]] = 1;
                        from[gin[i]] = now;
                    }
                while (q.Count > 0)
                {
                    now = q.Dequeue();
                    for (int i = qs[now]; i < qs[now + 1]; i++)
                        if (used[gin[i]] == 0 &&
                        gr[gin[i]] % m != gr[from[now]] % m &&
                        gr[gin[i]] / m != gr[from[now]] / m) 
                        {
                            q.Enqueue(gin[i]);
                            used[gin[i]] = 1;
                            from[gin[i]] = now;
                        }
                }
                now = t;
                while (true)
                {
                    cyc.Add(now);
                    now = from[now];
                    if (now == -1)
                        return cycle(t, shift + 1);
                    if (now == t)
                        break;
                }
                return cyc;
            }
            int step()
            {
                int t = teta();
                outp();
                if (t < 0)
                    return -1;
                move(t);
                return t;
            }
            void outp()
            {
                log = log +  "\nПришёл в состояние со следующим распределением:\n\n";
                int c = 0;
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        log += "\t(" + cost[i][j] + ") ";
                        if (gr.Contains(i * m + j))
                            log += "" + weight[i][j];
                        else log += "-";
                        c += weight[i][j] * cost[i][j];
                    }
                    log += "\t| " + v[i];
                    log += "\n";
                }
                for (int j = 0; j < m; j++)
                    log += "\t" + h[j];
                log += "\nСуммарная стоимость: "+c+"\n";
                
            }
        public

        trans(List<int> s, List<int> c, List<List<int>> co)
        {
            cost = co;
            seller = s;
            customer = c;
            n = s.Count;
            m = c.Count;
            fictive = 0;
        }
        public
        string solve(int meth)
        {
            log = "";
            create_wei(meth);
            while (step() >= 0)
                ;
            log += "\n\nОптимальное расписание следующее:";
            if (fictive == 1)
                n--;
            else if (fictive == -1)
                m--;
            for (int i = 0; i < m; i++)
                for (int j = 0; j < m; j++)
                    if (gr.Contains(i * m + j))
                        log += "\nПродавец № " + (i + 1) + " поставляет покупателю № " + (j + 1) + " товар в объёме " + weight[i][j];
            if (fictive == 1)
                n++;
            else if (fictive == -1)
                m++;
            return log;
        }

    }
 
}
