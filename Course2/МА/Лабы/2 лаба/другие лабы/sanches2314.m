


clf;
 syms x y Ur Title % ������������� ���������� ����������
 syms x_new y_new Expr Message
 Ur = 'y*cos(x)/sin(x)'; 
 Expr = ['Dy = ', char(Ur)]; 
 y = dsolve(Expr, 'x'); % ������� ����������������� ���������
 y = y(1);
 fprintf('y = ');
 Message = ['y=', char(y)];
 pretty(simplify(y)); % ������ ������� ���������
 grid on; hold on; % �������� ������������ �����
 xlabel('X axis'); % ����������� ��� OX
 ylabel('Y axis'); % ����������� ��� OY
 x_new = -10:0.1:10; % ��������� ����� �������� ����������
 y = subs(y, 'x', x_new); % ����������� ���������

 for cycle = 0 : 1 : 5 % ��������� �������� ������. ���������
 val = cycle;
 y_new = subs(y, 'C91', val); % ����������� ���������
 plot(x_new, y_new); % ���������� ������������ ������
 end;
 Title = ['Integral Curves of Equation: ', char(Expr)];
 title(char(Title)); % ��������� ������� �������
 legend(char(Message)); % ������� �������