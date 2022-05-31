----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 31.05.2022 21:16:20
-- Design Name: 
-- Module Name: MICROPROCESSOR_TEST - Behavioral
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity MICROPROCESSOR_TEST is
end MICROPROCESSOR_TEST;

architecture Behavioral of MICROPROCESSOR_TEST is

component MICROPROCESSOR is
    Port ( CLK : in STD_LOGIC;
          ADDR : in STD_LOGIC_VECTOR (7 downto 0)
 );
end component;

--inputs
signal CLK:  STD_LOGIC :='0' ;
signal ADDR :  std_logic_vector(7 downto 0) := (others => '0');

begin

MICROPROCESSOR_MAP: MICROPROCESSOR
PORT MAP(
CLK => CLK,
ADDR => ADDR
);

--SIMULATE CLOCK
SIM_CLK : process
begin
CLK <= NOT(CLK);
WAIT FOR 5ns;
end process;


--THE INSTRUCTIONS HAVE BEEN INITIALIZED IN THE INSTRUCTION BANK FILE
--WE LOADED THE 4 FIRST SLOTS
--WE WILL NOW SEE IF THE COMPONENTS WORK PROPERLY BY ANALIZING THEIR FIELD CONTENTS
ADDR <= "00000000" ,
        "00000001" after 100ns,
        "00000010" after 200ns,
        "00000011" after 300ns,
        "00000100" after 400ns,
        "00000101" after 500ns,
        "00000110" after 600ns,
        "00000111" after 700ns;
end Behavioral;
