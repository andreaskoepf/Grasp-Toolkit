classdef CustomTimer < handle
    properties
        CurrentData
        
    end
    
    properties(SetAccess=protected,GetAccess=protected)
        Timer
    end

    methods
        function t=CustomTimer(currentData)
            t.Timer=timer;
            t.CurrentData=currentData;
            set(t.Timer,'TimerFcn',{@t.callback1})

        end
        
        function delete(t)
            disp('Deleting timer')
            delete(t.Timer) 
        end
        
        function start(t)
            start(t.Timer)
        end
        
        
        function callback1(t,obj,evnt)
            for n=1:length(t.CurrentData);
                pause(0.5)
                disp(t.CurrentData(n))
            end
            disp(fieldnames(evnt))
        end


    end
end


