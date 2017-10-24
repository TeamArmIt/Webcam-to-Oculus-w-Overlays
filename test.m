% Takes the seridal data and simulates the rotation on a sphere
%Author: Saimouli Katragadda
%%
clear all; clc;
%function rotsim(roll,yaw,pitch)
% %Axis
% plot3(0,0,0);
% axis vis3d
% axis off
% hold on 
% plot3([0,1], [0,0], [0,0],'r'); %x-axis
% plot3([0,0],[0,0],[0,1],'g'); %y-axis
% plot3([0,0],[0,-1],[0,0],'b'); %z-axis
% hold off
%%
% pitch=[pi; 2*pi; 1; 3*pi/4];
% yaw=[0; 0; 0;0];
% roll=[0; 0; 0;0];
fileName= fopen('headtrackingdata.txt');

if fileName >0
%for i=1:length(pitch) % as yaw,pitch and roll have same length
    while ~feof (fileName) % not the end of the file
        % read from file
        data= textscan(fileName, '%f %f %f');
        [x,y,z] = sphere;h=surf(x,y,z);axis('square'); 

        title('Oculus HeadTracking')
        xlabel('x'); ylabel('y'); zlabel('z');

        %Rotate Object
%         rotate(h,[1,0,0],(pitch(i)) %x
%         rotate(h,[0,0,1],(yaw(i)) %y  +90 according to the oculus frame attachment 
%         rotate(h,[0,-1,0],(roll(i)) %z
        view(0,0);
        drawnow
    end
    fclose(fineName);
end
%%

% clear; clc; close all; 
% %Creat Port
% s = serial('COM1')
% %Open Port 
% fopen(s);
% %Set Terminator
% set(s,'Terminator',' ');fscanf(s);
% %Read First Data for Calibration 
% a(1,:)=fscanf(s,'%f');
% [yaw_c, pitch_c, roll_c]=quat2angle(a(1,:));
% for frame=1:1:1000
%     frame
%     %Read Data;
%     a(frame,:)=fscanf(s,'%f');
%     %Convert Quaternion to Roll Pitch Yaw
%     [yaw, pitch, roll] = quat2angle(a(frame,:));
%     %Visualize Data On Sphere Or any Other Objects
%     [x,y,z] = sphere;h = surf(x,y,z);axis('square'); 
%     title('AOL TEAM')
%     xlabel('x'); ylabel('y'); zlabel('z');
%     %Rotate Object
%     rotate(h,[1,0,0],(roll-roll_c)*180/pi)
%     rotate(h,[0,1,0],(pitch-pitch_c)*180/pi)
%     rotate(h,[0,0,1],(yaw-yaw_c)*180/pi+90)
%     view(0,0);
%     drawnow
% end
% fclose(s);
