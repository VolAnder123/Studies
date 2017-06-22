%������� 4. ������������ ������������������ ���� �� ����������. �������
%��������
syms p n leibniz_limit an an_diff
is_converges = false;%���� is_converges = true ����� ��� ��������
an = ((-1)^n) * sin(pi/(2 * n ^ (1/2))) / (3*n + 1) ^ (1/2);
p = limit(abs(subs(an, n, n + 1)/an),n,inf);%������� �'��������
if(p == 1)
    p = int(abs(an),1,inf);%������������ �������
    if(p ~= inf)    
        disp('��� �������� ���������');
        is_converges = true;
    end;
elseif(p < 1)
    disp('��� �������� ���������');
    is_converges = true;
end;
if(is_converges == false) 
    an_diff = diff(abs(an), n);
    assume(n>=1);
    if(isAlways(an_diff<0))%�������� �� ���������� ��������
        leibniz_limit = limit(abs(an),n,inf);
        if(leibniz_limit == 0)
            disp('��� �������� �������');
        else
            disp('��� ����������');
        end;
    else
        disp('��� ����������');
    end;
end;
%��� �������� �������