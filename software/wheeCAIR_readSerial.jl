using LibSerialPort, Plots, Dates

name = "/dev/ttyACM0";
baudrate = 9600;

sp = LibSerialPort.open(name, baudrate)
sleep(1);

function getdata()
	if bytesavailable(sp) > 0
		x = String(readline(sp));

		if occursin(x, "Checksum Fail")
			return [MACK, missing, missing, missing, missing, missing, missing]
		else
		    return x
		end
	else
		sleep(15);
	end
end

r =
function readloop(r = 1)
	try
		while r == 1
			d = getdata()
			if !isnothing(d)
				currentfilename = string(today())*"_MACK.txt"
				if !isfile(currentfilename)
					currentfile = open(currentfilename, "w")
				else
					currentfile = open(currentfilename, "a")
				end
				write(currentfile, d*"\n")
				close(currentfile)
				println(d)
			end
		end
	catch e
		if e isa InterruptException
			println("ended by user")
		end
		rethrow(e)
		LibSerialPort.close(sp)
	end
end

readloop()

# LibSerialPort.close(sp)
