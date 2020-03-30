using CSV
using DataFrames
using Plots
using Dates

X =
    CSV.read.(
        joinpath.(
            pwd(),
            "data/",
            filter!(s -> occursin(r"\.TXT", s), readdir("data")),
        ),
        header = false,
    )

for i = 1:length(X)
    X[i][!, 2] = Dates.DateTime.(X[i][!, 2], "YYYY-mm-dd HH:MM:SS");
    if X[i][:, 2] .> Dates.DateTime("2019-11-03T02:00:00")
        X[i][:, 2] = X[i][:, 2] .+ Dates.Hour(1);
    end
end

X[i][:, 2] .> Dates.DateTime("2019-11-03T02:00:00")
    X[i][:, 2] = X[i][:, 2] .+ Dates.Hour(1);

# clf()
p = plot(X[1][!, 2], X[1][!, 3], label = X[1][1, 1])
for i = 2:length(X)
    p = plot!(X[i][!, 2], X[i][!, 3], label = X[i][1, 1])
end
display(p)


# xlabel("Timestamp"); ylabel("Temperature (°C)")
# legend()
# gcf()

min(X[1][1, 1])
