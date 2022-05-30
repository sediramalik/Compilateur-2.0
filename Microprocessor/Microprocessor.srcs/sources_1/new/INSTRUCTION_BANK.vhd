----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 30.05.2022 15:30:17
-- Design Name: 
-- Module Name: INSTRUCTION_BANK - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity INSTRUCTION_BANK is
    Port ( ADDR : in STD_LOGIC_VECTOR (7 downto 0);
           CLK : in STD_LOGIC;
           OUTPUT : out STD_LOGIC_VECTOR (31 downto 0));
end INSTRUCTION_BANK;

architecture Behavioral of INSTRUCTION_BANK is
type MEM_TAB  is array(255 downto 0) of std_logic_vector(31 downto 0);
signal MEM : MEM_TAB;
begin

--TESTS FOR FINAL PART
MEM(0) <= x"0000003F";
MEM(1) <= x"00000021";
MEM(2) <= x"0000004C";
MEM(3) <= x"0000006D";
process
begin
    wait until(CLK'event);
            if (CLK='1') then OUTPUT <= MEM(to_integer(unsigned(ADDR)));       
            end if;                          
end process;


end Behavioral;
