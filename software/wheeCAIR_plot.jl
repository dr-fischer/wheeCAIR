### A Pluto.jl notebook ###
# v0.14.5

using Markdown
using InteractiveUtils

# This Pluto notebook uses @bind for interactivity. When running this notebook outside of Pluto, the following 'mock version' of @bind gives bound variables a default value (instead of an error).
macro bind(def, element)
    quote
        local el = $(esc(element))
        global $(esc(def)) = Core.applicable(Base.get, el) ? Base.get(el) : missing
        el
    end
end

# ╔═╡ b7da6276-89c4-4603-ab93-f66def8d18f6
begin
	using CSV, DataFrames, Plots, Dates, TimeSeries, PlutoUI, LibSerialPort
	plotly()
end;

# ╔═╡ 09dfce1a-8b85-472c-b281-4c5e1d3f8304
sensorName = "MACK"

# ╔═╡ 6da26e9c-3c1a-4212-b53d-8ea742725f38
currentfilename = string(today())*"_"*sensorName*".txt"

# ╔═╡ 98598ea0-e4f3-41ef-9b56-cf4b3537aeaf
md"""
**Turn autoupdate on/off:**
$(@bind ticks Clock(30,true))
"""

# ╔═╡ ad38d8a6-c0b0-11eb-3a49-0d07d6e53c96
function readData()
	return CSV.read(currentfilename, DataFrame, header = ["Sensor", "Timestamp", "Temp_C", "RH", "P_hPa", "VOC_arb", "PM_ugm3"])
end;

# ╔═╡ 1c5286fb-1234-4370-b12b-a697b0cbf4e4
begin
	ticks
	currentData = readData()
end

# ╔═╡ 8a13b676-a493-44cb-8e2a-5513ba0925fb
md"""
# Current Data: $(currentData[1, 1])
"""

# ╔═╡ 9b99e2f3-0074-46f5-9e55-1f8632dc515e
x = DateTime.(currentData.Timestamp, "y-m-d HH:MM:SS");

# ╔═╡ c123f16a-dc62-436d-be64-b07dbc2f9461
begin
	p1 = plot(x, currentData.Temp_C, legend = false, border = :box, ylabel = "Temperature (°C)", xlabel = nothing, color = 2, linewidth = 2);
	p2 = plot(x, currentData.RH, legend = false, border = :box, ylabel = "RH (%)", xlabel = nothing, linewidth = 2);
	p3 = plot(x, currentData.P_hPa, legend = false, border = :box, ylabel = "Pressure (hPa)", xlabel = nothing, color = 3, linewidth = 2);
	p4 = plot(x, currentData.PM_ugm3, legend = false, border = :box, ylabel = "[PM] (μg / m³)", xlabel = "Timestamp", color = 4, linewidth = 2);
end;

# ╔═╡ 0446c13c-ad2a-42c1-ac84-aa2cefc29db5
begin
	l = @layout [a; b; c; d]
	plot(p1, p2, p3, p4, layout = l)
	plot!(size=(650,1000))
end

# ╔═╡ Cell order:
# ╟─8a13b676-a493-44cb-8e2a-5513ba0925fb
# ╠═09dfce1a-8b85-472c-b281-4c5e1d3f8304
# ╠═6da26e9c-3c1a-4212-b53d-8ea742725f38
# ╟─98598ea0-e4f3-41ef-9b56-cf4b3537aeaf
# ╟─0446c13c-ad2a-42c1-ac84-aa2cefc29db5
# ╟─1c5286fb-1234-4370-b12b-a697b0cbf4e4
# ╟─ad38d8a6-c0b0-11eb-3a49-0d07d6e53c96
# ╟─b7da6276-89c4-4603-ab93-f66def8d18f6
# ╟─9b99e2f3-0074-46f5-9e55-1f8632dc515e
# ╟─c123f16a-dc62-436d-be64-b07dbc2f9461
