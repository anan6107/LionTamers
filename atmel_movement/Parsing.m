fid = fopen('Total_Grass.txt');
out = textscan(fid,'%*D -> Color Temp: %*d K - Lux: %*d - R: %d G: %d B: %d C: %d');
% out will be a 1x4 cell array
X = horzcat(out{:});
% out2 will be 2d matrix of size Nx4
fclose(fid);
% class(X{1, 1});
X= double(X);
%class(X{1, 1});
%idx = kmeans(X,2);

%X=%your maxtrix
m=X(:,1:3)./repmat(X(:,4),1,3);%divide not multiply
plot3(m(:,1),m(:,2),m(:,3))

[idx,C,sumd,D] = kmeans(m,2);
%[idx,C] = kmeans(X,2);

%[idx,C] = kmeans(X,2);
%  covariance matrix 3 by 3 matrix
% optimal bayesian binary detection scheme
%idx = kmeans(out2,2);  %out2 is the matrix ; 2 is the number of clusters