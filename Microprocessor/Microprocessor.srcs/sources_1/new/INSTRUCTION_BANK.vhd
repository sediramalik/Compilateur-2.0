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
MEM(0) <= x"01010203"; --ADD @0x01 @0x02 @0x03 (@ ARE IN THE REGISTER FILE)
MEM(1) <= x"02010203"; --MUL @0x01 @0x02 @0x03 (@ ARE IN THE REGISTER FILE)
MEM(2) <= x"02010203"; --SOU @0x01 @0x02 @0x03 (@ ARE IN THE REGISTER FILE)
MEM(3) <= x"04010203"; --DIV @0x01 @0x02 @0x03 (@ ARE IN THE REGISTER FILE)
MEM(4) <= x"05010200"; --COP @0x01 @0x02 (@ ARE IN THE REGISTER FILE)
MEM(5) <= x"06010200"; --AFC @0x01 @0x02 (@ ARE IN THE REGISTER FILE)
MEM(6) <= x"07010200"; --LOAD @0x01 @0x02 (@ ARE IN THE REGISTER FILE)
MEM(7) <= x"08010200"; --STORE @0x01 @0x02 (@ ARE IN THE REGISTER FILE)

process
begin
    wait until CLK'Event and CLK = '1';
        OUTPUT <= MEM(to_integer(unsigned(ADDR)));       
                        
end process;


end Behavioral;
