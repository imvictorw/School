#   Course: IT102 Section C
#   Authors: Victor Woo
#   Date: 28/9/2016
#   Assignment: PP4

print("Price per unit is $5.00")
print("Sales tax rate is 9%")

unitsBUY = input("Enter the number of units you wish to buy ")
pretax = float(unitsBUY) * 5
totaltax = float(pretax) * 0.09
totalprice = pretax + totaltax


print("You are purchasing ", float(unitsBUY), " units" )
print("Your pre-tax total is $", float(pretax))
print("Your total tax  is $", float(totaltax))
print("Your total price is $", float(totalprice))
