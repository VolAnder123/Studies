clf;
syms x y Ur Title; % ������������� ���������� ����������
syms x_new y_new Expr Message;
%Ur = '-(x * y) / sqrt(1 + x^2)'; % �����. ����. ����� �������.
%Ur = '-(1+y^2)/(1+x^2)'; % �����. ����. ����� �������.
%Ur = '1+x';
%Ur = '(3*x*(2+y^2))/((x^2 + 3)*2*y)';
%Ur = 'sin(x+y) - sin(x-y)';
Ur = 'sin(x-y)';
Expr = ['Dy = ', char(Ur)]; % ������������ �������. ���������
y = dsolve(Expr, 'x'); % ������� ����������������� ���������
%y = y(2);
fprintf('y = ');
Message = ['y=', char(y)];
pretty(simplify(y)); % ������ ������� ���������
grid on; hold on; % �������� ������������ �����
xlabel('X axis'); % ����������� ��� OX
ylabel('Y axis'); % ����������� ��� OY
x_new = -10:0.1:10; % ��������� ����� �������� ����������
y = subs(y, x, x_new); % ����������� ���������
axis([0 3 0 4]);
for cycle = -5 : 1 : 5 % ��������� �������� ������. ���������
    val = cycle;    
    y_new = subs(y, 'C22', val); % ����������� ���������
    %plot(x_new, y_new); % ���������� ������������ ������
    plot(x_new, y_new);
end;
Title = ['Integral Curves of Equation: ', char(Expr)];
title(char(Title)); % ��������� ������� �������
legend(char(Message)); % ������� �������