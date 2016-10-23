
local mystr = require "libstr"

print(mystr.find("zhaosheng", "sh"))

print(mystr.sub("zhaosheng", 3, 6))

local b, e = mystr.find("zhaosheng", "shg")
if b ~= nil then
print (b .. '  ' .. e)
else
print (b)
end
